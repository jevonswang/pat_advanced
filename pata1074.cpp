/*
http://pat.zju.edu.cn/contests/pat-a-practise/1074

1074. Reversing Linked List (25)

Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node{
	int address;
	int value;
	int next;
	int last;
}node[100000];

int main(){
		
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	int start, n, k;
	scanf("%d%d%d",&start,&n,&k);

	for (int i = 0; i < n; i++){
		int address;
		scanf("%d",&address);
		node[address].address = address;
		scanf("%d%d", &node[address].value, &node[address].next);
	}

	int address = start;
	int count = 0;
	vector<Node> list,temp;
	while (address != -1){
		temp.push_back(node[address]);
		address = node[address].next;
		count++;
		if (count == k){
			while (!temp.empty()){
				list.push_back( temp.back());
				temp.pop_back();
			}
			count = 0;
		}
	}
	while (!temp.empty()){
		list.push_back(temp.front());
		temp.erase(temp.begin());
	}

	int i;
	for (i = 0; i < list.size()-1; i++){
		printf("%05d %d %05d\n",list[i].address,list[i].value,list[i+1].address);
	}
	printf("%05d %d -1\n", list[i].address, list[i].value);

	
	return 0;
}
