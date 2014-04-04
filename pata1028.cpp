/*
http://pat.zju.edu.cn/contests/pat-a-practise/1028

1028. List Sorting (25)

Excel can sort records according to any column. Now you are supposed to imitate this function.

Input

Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output

For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90

*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Stu{
	int id;
	char name[10];
	int grade;
};

bool cmp1(Stu a,Stu b){
	return a.id < b.id;
}


bool cmp2(Stu a, Stu b){
	int res;
	res = strcmp(a.name,b.name);
	if (res == 0){
		return a.id < b.id;
	}
	else return res < 0;
}

bool cmp3(Stu a, Stu b){
	int res;
	res = a.grade - b.grade;
	if (res == 0){
		return a.id < b.id;
	}
	else return res < 0;
}


int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	int n, c;
	scanf("%d %d",&n,&c);

	vector<Stu> list;
	Stu s;
	for (int i = 0; i < n; i++){
		scanf("%d %s %d",&s.id,&s.name,&s.grade);
		list.push_back(s);
	}

	if(c==1){
		sort(list.begin(),list.end(),cmp1);
	}
	else if(c==2){
		sort(list.begin(),list.end(),cmp2);
	}
	else if (c == 3){
		sort(list.begin(), list.end(), cmp3);
	}

	for (int i = 0; i < n; i++){
		printf("%06d %s %d\n", list[i].id, list[i].name, list[i].grade);
	}

	return 0;
}
