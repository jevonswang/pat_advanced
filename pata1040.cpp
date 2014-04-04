/*
http://pat.zju.edu.cn/contests/pat-a-practise/1040

1040. Longest Symmetric String (25)

Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int main(){

	char s[1000];
	gets(s);
	int len = strlen(s);

	int index=0;
	int max=0;
	for(int i=0;i<len;i++){
		int j = 0;
		while(s[i+j]==s[i-j] && i-j>=0 && i+j<len)j++;
		if(max<2*j-1) max = 2*j-1;
	}

	for(int i=0;i<len-1;i++){
		int a = i;
		int j = a+1;
		int t = 2;
		while(s[a]==s[j] && a>=0 && j<len){a--;j++;t+=2;}
		t-=2;
		if(max<t) max = t;

	}

	printf("%d\n",max);


	return 0;
}