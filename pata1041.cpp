/*
http://pat.zju.edu.cn/contests/pat-a-practise/1041

1041. Be Unique (20)

Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 104]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:

Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=105) and then followed by N bets. The numbers are separated by a space.

Output Specification:

For each test case, print the winning number in a line. If there is no winner, print "None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int num[100001];
int flag[10001];

int main()
{
	
	//freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);
	


	for (int i = 0; i <= 10001; i++){
		flag[i] = 0;
	}

	int n;
	scanf("%d",&n);
	for (int i = 0; i < n;i++){
		scanf("%d",&num[i]);
		if (flag[num[i]] == 1)
			flag[num[i]] = -1;
		if (flag[num[i]] == 0)
			flag[num[i]] = 1;	
	}

	bool f = false;
	for (int i = 0; i < n; i++){
		if (flag[num[i]] == 1){
			printf("%d\n", num[i]);
			f = true;
			break;
		}
	}

	if (f == false){
		printf("None\n");
	}

	return 0;
}
