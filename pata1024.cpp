/*
http://pat.zju.edu.cn/contests/pat-a-practise/1024

1024. Palindromic Number (25)

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

#define max(a,b) ((a>b)?a:b)

using namespace std;

class Big {
private:
	vector<int> digits;

public:
	Big(){}
	Big(char * str){
		int len = strlen(str);

		for(int i = len-1;i>=0;i--)
			digits.push_back(str[i]-'0');
	}

	Big operator+(const Big &another) const{
		Big ans;
		int len1 = digits.size();
		int len2 = another.digits.size();
		int len = max(len1,len2);
		int carry = 0;
		for(int i=0;i<len;i++){
			int d = carry;
			if(i<len1 ) d+=digits[i];
			if(i<len2 ) d+=another.digits[i];
			ans.digits.push_back(d%10);
			carry = d / 10;
		}
		if(carry > 0){
			ans.digits.push_back(carry);
		}
		return ans;
	}

	bool operator==(const Big &another)const{
		if(digits.size()!=another.digits.size())
			return false;
		for(int i=0;i<digits.size();i++){
			if(digits[i]!=another.digits[i]){
				return false;
			}
		}
		return true;
	}

	Big reverse(){
		Big ans;
		int len = digits.size();
		int i=0;
		while(digits[i]==0)
			i++;
		for(int j = 0;j<len-i;j++)
			ans.digits.push_back(digits[len-1-j]);
		return ans;
	}

	void print(char *tail = ""){
		int len =  digits.size();
		for(int i=0;i<len;i++){
			cout << digits[len-1-i];
		}
		cout<<tail;
	}

	bool IsPalindromic(){
		int i = 0;
		int len = digits.size();
		for(int i = 0;i<len/2;i++)
			if(digits[i]!=digits[len-1-i])
				return false;
		return true;
	}
};



int main() {
	char str[13];
	int k;

	scanf("%s %d", str, &k);

	Big b(str);

	int nstep = 0;

	while ((!b.IsPalindromic()) && nstep < k) {
		nstep++;
		b = b + b.reverse();
	}

	b.print("\n");
	printf("%d", nstep);

	return 0;
}

