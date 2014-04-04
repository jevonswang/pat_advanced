/*
http://pat.zju.edu.cn/contests/pat-a-practise/1052

1052. Linked List Sorting (25)

A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node{
	int address;
	int data;
	int next;
}node[100001],link[100001];


int comp (const void *aa, const void * bb)
{
    Node *a = (Node *)aa;
    Node *b = (Node *)bb;
    return a->data - b->data;
}

int main(){

//	freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\input.txt","r",stdin);

	int n;
	scanf("%d",&n);
	int start;
	scanf("%d",&start);

	if(start == -1){
		printf("0 %d\n",n,start);
		return 0;
	}

	int address,data,next;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&address,&data,&next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}

	int count = 0;
	next = start;
	while(next!=-1){
		link[count++] = node[next];
		next = node[next].next;
	}

	qsort(link , count, sizeof(Node), comp );

	printf("%d %05d\n",count,link[0].address);
	for(int i=0;i<count-1;i++){
		printf("%05d %d %05d\n",link[i].address,link[i].data,link[i+1].address);
	}
	printf("%05d %d -1\n",link[count-1].address,link[count-1].data);

	return 0;
}