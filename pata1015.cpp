/*
http://pat.zju.edu.cn/contests/pat-a-practise/1015


1015. Reversible Primes (20)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No

*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){

	if (n == 0 || n == 1)
		return false;

	int s = (int)sqrt(n);
	for (int i = 2; i <= s; i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

int reverse(int n,int d){


	int ret;
	int digit[100];
	int t = 0;

	if (n == 0){
		return 0;
	}

	while (n != 0){
		digit[t++] = n%d;
		n = n / d;
	}

	ret = 0;
	for(int i = 0; i < t; i++){
		ret = ret*d + digit[i];
	}

	return ret;
}


int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);
	int n, d;
	cin >> n;
	while (n >= 0){
		cin >> d;
		if (!isPrime(n)){
			cout << "No" << endl;
			cin >> n;
			continue;
		}
		int re = reverse(n,d);
		if (!isPrime(re)){
			cout << "No" << endl;
			cin >> n;
			continue;
		}
		cout << "Yes" << endl;
		cin >> n;
	}
	return 0;
}
