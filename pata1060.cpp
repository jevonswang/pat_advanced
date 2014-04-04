/*
http://pat.zju.edu.cn/contests/pat-a-practise/1060

1060. Are They Equal (25)

If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,i,j,t;
	cin>>n;
	char a[100],b[100];
	char aa[100],bb[100];
	int sa=0,sb=0;
	int ta=0,tb=0;
	cin>>a>>b;
	for(i=0;i<strlen(a);i++)
	  if(a[i]=='.')break;
    sa=i;
	for(i=0;i<strlen(b);i++)
	  if(b[i]=='.')break;
    sb=i;
    
	i=0;j=0;
	while(1)
	{
		if(((a[i]=='0')&&(j==0))||(a[i]=='.'))i++;
		else
		{
         aa[j]=a[i];i++;j++;
		 if(j==1)ta=i;
		}
	    if(j==n)break;
	}

	i=0;j=0;
	while(1)
	{
		if(((b[i]=='0')&&(j==0))||(b[i]=='.'))i++;
		else
		{
          bb[j]=b[i];i++;j++;
		  if(j==1)tb=i;
		}
		if(j==n)break;
	}
	aa[n]='\0';
	bb[n]='\0';
	ta--;tb--;
	sa=sa-ta;if(sa<0)sa++;
	sb=sb-tb;if(sb<0)sb++;

	if((strcmp(aa,bb)==0)&&(sa==sb))
	{

		cout<<"YES ";
		if(strcmp(aa,"")==0)cout<<"0";
		else cout<<"0."<<aa;
		if(sa!=0)
		 cout<<"*10^"<<sa<<endl;
	}
	else
	{
		cout<<"NO ";
		if(strcmp(aa,"")==0)cout<<"0";
		else cout<<"0."<<aa;
		if(sa!=0)
		 cout<<"*10^"<<sa;
		if(strcmp(bb,"")==0)cout<<" 0";
		else cout<<" 0."<<bb;
		if(sb!=0)
		 cout<<"*10^"<<sb<<endl;
	}
    
	return 0;
}