/*
http://pat.zju.edu.cn/contests/pat-a-practise/1029

1029. Median (25)

Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13

*/

#include<cstdio>
using namespace std;

int a[1000000];
int b[1000000];

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	int na, nb;
	scanf("%d",&na);
	for (int i = 0; i < na; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d", &nb);
	for (int i = 0; i < nb; i++){
		scanf("%d", &b[i]);
	}

	int m = (na + nb + 1) / 2;

	int i = 0, j = 0, index = 0;
	int result;
	while (i != na && j != nb && index != m) {
		if (a[i] <= b[j]) {
			result = a[i];
			++i, ++index;
		}
		else {
			result = b[j];
			++j, ++index;
		}
	}

	while (i != na && index != m) {
		result = a[i];
		++i; ++index;
	}

	while (j != nb && index != m) {
		result = b[j];
		++j, ++index;
	}

	printf("%ld\n", result);



	return 0;
}
