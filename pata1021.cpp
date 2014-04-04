/*
http://pat.zju.edu.cn/contests/pat-a-practise/1021

1021. Deepest Root (25)

A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components

*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> adj[10001];
bool visit[10001];

void dfs(int i,int depth,int &height,vector<int> &farthestnode){
	visit[i] = true;

	if (depth > height){
		height = depth;
		farthestnode.clear();
		farthestnode.push_back(i);
	}
	else if (depth == height){
		farthestnode.push_back(i);
	}

	for (int j = 0; j < adj[i].size(); j++){
		if (visit[adj[i][j]] == false){
			dfs(adj[i][j], depth + 1, height, farthestnode);
		}
	}
}

int main(){
		
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	int n;
	int a, b;
	scanf("%d",&n);

	if (n == 1){
		printf("1\n");
		return 0;
	}

	for (int i = 0; i < n-1; i++){
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i <= n; i++){
		visit[i] = false;
	}

	vector<int> farthestnode;

	int component = 0;
	int height = 0;

	for (int i = 1; i <= n; i++){
		if (visit[i] == false){
			visit[i] = true;
			dfs(i, 0, height, farthestnode);
			component++;
		}
	}

	if (component != 1){
		printf("Error: %d components",component);
		return 0;
	}

	int index = farthestnode[0];
	farthestnode.clear();
	

	for (int i = 0; i <= n; i++){
		visit[i] = false;
	}

	dfs(index,0,height,farthestnode);
	farthestnode.push_back(index);

	sort(farthestnode.begin(),farthestnode.end());

	for (int i = 0; i < farthestnode.size(); i++){
		printf("%d\n",farthestnode[i]);
	}


	return 0;
}