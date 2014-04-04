/*
http://pat.zju.edu.cn/contests/pat-a-practise/1063

1063. Set Similarity (25)

Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, k;
int ar[51][10001];

int getnc(int a, int b)
{
    int c1 = ar[a][0], c2 = ar[b][0];
    int i = 1, j = 1;
    int ret = 0;
    
    while(i <= c1 && j <= c2) {
        if (ar[a][i] < ar[b][j]) {
            i ++;
        } else if(ar[a][i] == ar[b][j]) {
            i ++;
            j ++;
            ret ++;
        } else {
            j ++;
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &m);
        ar[i][0] = m;
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &ar[i][j]);
        }
        sort(ar[i]+1, ar[i]+m+1);
        int index = 1;
        
        for (int j = 1; j <= m; j ++) {
            ar[i][index ++] = ar[i][j];
            while (j <= m && ar[i][j] == ar[i][j + 1])
                j ++;
        }
        ar[i][0] = index - 1;
    }
    
    scanf("%d", &k);
    for (int i = 0; i != k; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int nc = getnc(a,b);
        printf("%.1lf%%\n", nc *100.0/(ar[a][0] + ar[b][0] - nc));
    }
    
    return 0;
}