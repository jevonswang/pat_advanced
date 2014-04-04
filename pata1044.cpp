/*
http://pat.zju.edu.cn/contests/pat-a-practise/1044

1044. Shopping in Mars (25)

Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:

1. Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
2. Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
3. Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.

If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=105), the total number of diamonds on the chain, and M (<=108), the amount that the customer has to pay. Then the next line contains N positive numbers D1 ... DN (Di<=103 for all i=1, ..., N) which are the values of the diamonds. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print "i-j" in a line for each pair of i <= j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.

If there is no solution, output "i-j" for pairs of i <= j such that Di + ... + Dj > M with (Di + ... + Dj - M) minimized. Again all the solutions must be printed in increasing order of i.

It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
Sample Output 2:
2-4
4-5
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;

int a[100005];
int s[100005];

struct Node{
	int start;
	int end;

	Node(int i,int j){
		start = i;
		end = j;
	}
};

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	s[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}

	vector<Node> res;
	int min=99999999;
	int sum;

	int i, j=2;

	for (i = 1; i <= n; i++){
		for (--j; j <= n; j++){
			sum = s[j]-s[i-1];
			if (sum >= m){
				if (sum == min){
					res.push_back(Node(i, j));
				}else if (sum < min){
					res.clear();
					res.push_back(Node(i, j));
					min = sum;
				}
				break;
			}
		}
	}

	for (int i = 0; i < res.size(); i++){
		printf("%d-%d\n",res[i].start,res[i].end);
	}

	return 0;
}