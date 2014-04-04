/*
http://pat.zju.edu.cn/contests/pat-a-practise/1003

1003. Emergency (25)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int INF = 1000000;
const int NUM = 505;
int map[NUM][NUM];
int team[NUM], isVisit[NUM];
int dist[NUM];
int ans, maxTeamNum;

void init(){
	int i, j;
	for (i = 0; i < NUM; i++){
		isVisit[i] = 0;
		team[i] = 0;
		dist[i] = INF;
		for (j = 0; j < NUM; j++){
			if (j != i){
				map[i][j] = INF;//初始化为无穷大，表示不连通
				map[j][i] = INF;
			}
		}
	}
}


void dijskra(int n, int source){

	int i, minDis = INF, index = 0, j;

	for (i = 0; i < n; i++){
		dist[i] = map[source][i];
	}

	isVisit[source] = 1;//将其加入已访问点的集合
	for (i = 0; i < n - 1; i++){
		minDis = INF;
		index = 0;
		for (j = 0; j < n; j++){
			if (!isVisit[j] && dist[j] < minDis){//找到最小距离点
				minDis = dist[j];
				index = j;
			}
		}
		isVisit[index] = 1;//将其加入已访问点的集合
		for (j = 0; j < n; j++){//更新源点与每个点之间的距离
			if (map[index][j]<INF && dist[j]>dist[index] + map[index][j])
				dist[j] = dist[index] + map[index][j];
		}
	}
}

void dfs(int n, int cId, int dest, int curDis, int curTeamNum){

	int i;
	isVisit[cId] = 1;
	if (cId == dest){
		if (curDis == dist[dest]){
			ans++;//最短路径数+1
			if (curTeamNum > maxTeamNum)
				maxTeamNum = curTeamNum;
		}
		return;
	}
	if (curDis > dist[dest])//当前的路径长度已经超过最短路径,就没有必要继续搜索了。
		return;
	for (i = 0; i < n; i++){
		if (!isVisit[i] && map[cId][i] < INF){//城市i未被访问过，且cId到i连通
			dfs(n, i, dest, curDis + map[cId][i], curTeamNum + team[i]);
			isVisit[i] = 0;
		}
	}
}

int main(){
	int n, m, source, dest, i;
	int c1, c2, l;

	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	cin >> n >> m >> source >> dest;

	init();
	
	for (i = 0; i < n; i++)
		cin >> team[i];
	
	for (i = 0; i < m; i++){
		cin >> c1 >> c2 >> l;
		map[c1][c2] = l;
		map[c2][c1] = l;
	}

	dijskra(n, source);

	for (i = 0; i < n; i++)
		isVisit[i] = 0;

	dfs(n, source, dest, 0, team[source]);

	cout << ans << " " << maxTeamNum << endl;

	return 0;
}