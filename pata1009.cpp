/*
http://pat.zju.edu.cn/contests/pat-a-practise/1009

1009. Product of Polynomials (25)

This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6

*/


#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct node
{
	int exp;
	double coe;
};

bool Pred(node a,node b)
{
	return a.exp>b.exp;
}

int main()
{
	node a[100];
	node b[100];
	node c[100];
	int n,m;

	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i].exp>>a[i].coe;
	cin>>m;
	for(int i=0;i<m;i++) cin>>b[i].exp>>b[i].coe;

	int t=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			c[t].exp=a[i].exp+b[j].exp;
			c[t].coe=a[i].coe*b[j].coe;
			t++;
		}

	sort(c,c+t,Pred);


	int s=t;
	for(int i=1;i<t;i++)
		if(c[i].exp==c[i-1].exp)
		{
			c[i].coe+=c[i-1].coe;c[i-1].coe=0;
			s--;
			if(fabs(c[i].coe)<1e-6)s--;
		}

    cout<<s;

	for(int i=0;i<t;i++)
		if(fabs(c[i].coe)>1e-6)
		printf(" %d %.1lf",c[i].exp,c[i].coe);

	return 0;
}