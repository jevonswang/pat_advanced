/*
http://pat.zju.edu.cn/contests/pat-a-practise/1004
1004. Counting Leaves (30)

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1

*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){

	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	vector<int> children[100];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int parent, child, k;
		cin >> parent >> k;
		for (int j = 0; j < k; j++){
			cin >> child;
			children[parent].push_back(child);
		}
	}

	queue<int> q,q_temp;
	bool isfirst = true;

	q.push(1);
	while (!q.empty()){

		int count = 0;
		while (!q.empty()){
			int node = q.front();
			q.pop();
			if (children[node].empty())
				count++;
			else{
				for (int i = 0; i < children[node].size(); i++){
					q_temp.push(children[node][i]);
				}
			}
		}

		if (isfirst){
			cout << count;
			isfirst = false;
		}
		else
			cout << " " << count;

		while (!q_temp.empty()){
			int t = q_temp.front();
			q.push(t);
			q_temp.pop();
		}
		

	}





	return 0;
}