/*
http://pat.zju.edu.cn/contests/pat-a-practise/1012

1012. The Best Rank (25)

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Stu{
	string id;
	int grade;
};

bool comp(Stu a, Stu b){
	return a.grade > b.grade;
}

int main(){

	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);


	int n, m;
	cin >> n >> m;

	vector<Stu> vc;
	vector<Stu> vm;
	vector<Stu> ve;
	vector<Stu> va;

	string id;
	int gc, gm, ge,ga;
	Stu temp;

	for (int i = 0; i < n; i++){
		cin >> id >> gc >> gm >> ge;
		ga = (ge + gm + gc) / 3;
		temp.id = id;
		temp.grade = ga;
		va.push_back(temp);
		temp.grade = gc;
		vc.push_back(temp);
		temp.grade = gm;
		vm.push_back(temp);
		temp.grade = ge;
		ve.push_back(temp);
	}

	sort(va.begin(), va.end(), comp);
	sort(vc.begin(), vc.end(), comp);
	sort(vm.begin(), vm.end(), comp);
	sort(ve.begin(), ve.end(), comp);


	int rank = 0;
	char name;
	for (int i = 0; i < m; i++){
		cin >> id;
		int j;
		for (j = 0; j < n; j++){
			if (va[j].id == id){
				rank = j;
				while (rank != 0 && va[rank - 1].grade == va[rank].grade)
					rank--;
				rank++;
				name = 'A';
				break;
			}
			else if (vc[j].id == id){
				rank = j;
				while (rank != 0 && vc[rank - 1].grade == vc[rank].grade)
					rank--;
				rank++;
				name = 'C';
				break;
			}
			else if (vm[j].id == id){
				rank = j;
				while (rank != 0 && vm[rank - 1].grade == vm[rank].grade)
					rank--;
				rank++;
				name = 'M';
				break;
			}
			else if (ve[j].id == id){
				rank = j;
				while (rank != 0 && ve[rank - 1].grade == ve[rank].grade)
					rank--;
				rank++;
				name = 'E';
				break;
			}
		}
		if (j == n){
			printf("N/A\n");
		}
		else {
			printf("%d %c\n",rank,name);
		}
	}



	return 0;
}


/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
*/