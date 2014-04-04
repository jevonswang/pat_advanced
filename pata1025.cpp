/*
http://pat.zju.edu.cn/contests/pat-a-practise/1025

1025. PAT Ranking (25)

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4


*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct node
{
	char ID[13];
	int score;
	int local_rank;
	int final_rank;
	int local_num;
};

bool Pred(node a,node b)
{
	if(a.score>b.score) return true;
	else if((a.score==b.score)&&(strcmp(a.ID,b.ID)<0)) return true;
	else return false;
}

int main()
{
	node *location[100];
	vector<node> list;
	int n;
	cin>>n;
	int sum=0;
	for(int group=0;group<n;group++)
	{
		int m;
		cin>>m;
		sum+=m;
		location[group]=new node[m];
		for(int i=0;i<m;i++)
		{
			cin>>location[group][i].ID>>location[group][i].score;
			location[group][i].local_num=group+1;
		}
		sort(location[group],location[group]+m,Pred);
		int pre_score=-1;
		for(int i=0;i<m;i++)
		{
			if(pre_score==location[group][i].score)location[group][i].local_rank=location[group][i-1].local_rank;
			else location[group][i].local_rank=i+1;
			pre_score=location[group][i].score;

			list.push_back(location[group][i]);
		}


	}
	sort(list.begin(),list.end(),Pred);
	cout<<sum<<endl;
	vector<node>::iterator p;
	int pre_score=-1;
	for(p=list.begin();p<list.end();p++)
	{
		cout<<p->ID<<" ";
		if(pre_score==p->score)p->final_rank=(p-1)->final_rank;
		else p->final_rank=p-list.begin()+1;
		pre_score=p->score;
		cout<<p->final_rank<<" "<<p->local_num<<" "<<p->local_rank<<endl;

	}
	return 0;

}




