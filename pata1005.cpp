/*
http://pat.zju.edu.cn/contests/pat-a-practise/1005

1005. Spell It Right (20)

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char n[1000];
	cin>>n;
	int len=strlen(n);
	int s=0;
	for(int i=0;i<len;i++)s+=n[i]-'0';

	char digit[10][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};

	int t=0;
	int d[100];
	if(s!=0)
	{
	while(s!=0)
	{
		d[t++]=s%10;
		s/=10;
	}
	}
	else d[t++]=0;
	for(int i=t-1;i>0;i--)cout<<digit[d[i]]<<" ";
	cout<<digit[d[0]]<<endl;



	return 0;
}