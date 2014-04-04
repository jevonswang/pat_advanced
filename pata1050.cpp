/*
http://pat.zju.edu.cn/contests/pat-a-practise/1050

1050. String Subtraction (20)

Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:

Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/

#include<iostream>
#include<cstring>
using namespace std;
char a[10000];
char b[10000];
int main()
{
	bool asc[256];
	gets(a);
	gets(b);
	int i;
	for(i=0;i<256;i++)asc[i]=true;
	int len_a=strlen(a);
	int len_b=strlen(b);
	for(i=0;i<len_b;i++)asc[b[i]]=false;
	for(i=0;i<len_a;i++)
		if(asc[a[i]])printf("%c",a[i]);

	return 0;
}