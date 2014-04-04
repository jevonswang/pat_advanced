/*
http://pat.zju.edu.cn/contests/pat-a-practise/1049


1049. Counting Ones (30)

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/

#include<iostream>
using namespace std;
int main(){
	long n;
	cin >> n;
	long count = 0;
    long i = 1;
    long current = 0,after = 0,before = 0;
	while((n / i) != 0){           
		current = (n / i) % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;

        if (current > 1)
			count = count + (before + 1) * i;
        else if (current == 0)
			count = count + before * i;
        else if(current == 1)
            count = count + before * i + after + 1;

        i = i * 10;
	}
	cout<<count<<endl;
	return 0;
}