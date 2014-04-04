/*
http://pat.zju.edu.cn/contests/pat-a-practise/1073

1073. Scientific Notation (20)

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/

#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<string>
using namespace std;


int main(){
		
//	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);
	
		string a;
		cin >> a;
		string b = "";


		int i;
		for (i = 1;; i++){
			if (a[i] == 'E')
				break;
			if (a[i] != '.')
				b += a[i];
		}

		i++;
		int exp = 0;
		int sign = 1;
		if (a[i++] == '-'){
			sign = -1;
		}

		while (i < a.size()){
			exp = exp * 10 + a[i] - '0';
			i++;
		}
		exp *= sign;

		int pos = 1;
		pos += exp;
		if (pos <= 0){
			for (int i = 0; i <= -pos; i++)
				b = "0" + b;
			b.insert(1, ".");
		}
		else{
			int len = b.size();
			if (pos >= len){
				for (int i = 0; i < pos - len; i++)
					b += "0";
			}
			else
				b.insert(pos, ".");
		}


		b = a[0] + b;

		cout << b << endl;
	
	return 0;
}
