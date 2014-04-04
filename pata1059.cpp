/*
http://pat.zju.edu.cn/contests/pat-a-practise/1059

1059. Prime Factors (25)

Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,s;
	cin>>n;
	cout<<n<<"=";
	//97532468=2^2*11*17*101*1291
	int i,j,t=0;
	int p[100],k[100];
	for(i=0;i<100;i++)
	{
		p[i]=0;k[i]=0;
	}
	s=n;
	for(i=2;i<=s;i++)
	{
		
		if(n%i==0)
		{
			p[++t]=i;
			k[t]++;
			n/=i;
		}
		while(n%i==0)
		{
			p[t]=i;
			k[t]++;
			n/=i;
		}
		if(n==1)break;
	}
	if(t!=0)
	{
	for(i=1;i<t;i++)
	{
		if(k[i]==1)cout<<p[i]<<"*";
		else cout<<p[i]<<"^"<<k[i]<<"*";
	}
	if(k[t]==1)cout<<p[t];
	 else cout<<p[t]<<"^"<<k[t];
	}
	else cout<<n;
	return 0;
}