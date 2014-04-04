/*
http://pat.zju.edu.cn/contests/pat-a-practise/1075

1075. PAT Judge (25)

The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/

#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int full[6];

struct Stu{
	int id;
	int p[6];
	int total;
	int num;
	bool submitted;
}stu[10001];

bool cmp(Stu a,Stu b){
	if (a.total != b.total)
		return a.total > b.total;
	else if (a.num != b.num)
		return a.num > b.num;
	else return a.id < b.id;
}

int main(){
		
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);

	int n, k, m;
	scanf("%d%d%d",&n,&k,&m);

	for (int i = 1; i <= k; i++)
		scanf("%d",&full[i]);

	for (int i = 0; i <= n; i++){
		stu[i].total = 0;
		stu[i].num = 0;
		stu[i].id = i;
		stu[i].submitted = false;
		for (int j = 0; j <= k; j++){
			stu[i].p[j] = -1;
		}
	}



	int stu_id, num, score;
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &stu_id, &num, &score);
		if (stu[stu_id].p[num] <= score){

			if (stu[stu_id].p[num] != full[num] && score == full[num]) stu[stu_id].num++;

			if (stu[stu_id].p[num] == -1){

				if (score != -1){
					stu[stu_id].p[num] = score;
					stu[stu_id].total += score;
				}
				else{
					stu[stu_id].p[num] = 0;
				}
			}
			else{
				stu[stu_id].total -= stu[stu_id].p[num];
				stu[stu_id].p[num] = score;
				stu[stu_id].total += score;
			}

			if (score!=-1)
				stu[stu_id].submitted = true;
		}
	}

	vector<Stu> list;
	for (int i = 1; i <= n; i++){
		if (stu[i].submitted)
			list.push_back(stu[i]);
	}

	sort(list.begin(),list.end(),cmp);

	int rank = 0;
	for (int i = 0; i < list.size(); i++){
		if (i == 0 || list[i].total != list[i - 1].total)
			rank = i + 1;
		printf("%d %05d %d",rank,list[i].id,list[i].total);
		for (int j = 1; j <= k; j++){
			if (list[i].p[j] != -1) printf(" %d", list[i].p[j]);
			else printf(" -");
		}
		printf("\n");
	}

	


	
	return 0;
}
