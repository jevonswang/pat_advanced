/*
http://pat.zju.edu.cn/contests/pat-a-practise/1046

1046. Shortest Distance (20)

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/

#include<iostream>
using namespace std;


int main(){
	int n;
	int *d;
	cin>>n;
	d = new int[n];
	int total = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
		total += d[i];
	}

	int *dd = new int[n];
	dd[0]=0;
	for(int i=1;i<n;i++){
		dd[i] = dd[i-1]+d[i-1];
	}

	int m;
	cin >> m;
	while(m--){
		int a,b;
		cin>>a>>b;
		if(a>b){
			int t=a;
			a=b;
			b=t;
		}

		a--;
		b--;
		if(a==-1)a=n-1;
		if(b==-1)b=n-1;


		int s = dd[b] - dd[a]; 


		if(s>total-s) s = total-s;
		printf("%d\n",s);
	}
	
	

	return 0;
}