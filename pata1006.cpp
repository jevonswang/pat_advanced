/*
http://pat.zju.edu.cn/contests/pat-a-practise/1006

1006. Sign In and Sign Out (25)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133

*/

#include<iostream>
using namespace std;
class t
{
public:
	int h,m,s;
};
class stu
{
public:
	char ID[15];
	t in,out;
};
bool compare(t a,t b)
{
	if(a.h>b.h)return true;
	else if(a.m>b.m)return true;
	else if(a.s>b.s)return true;

	return false;
}

int main()
{
	int n;
	cin>>n;
	stu *s=new stu[n];
	int unlocked=0,locked=0;
	t unlock_t,lock_t;
	unlock_t.h=23;unlock_t.m=59;unlock_t.s=59;
	lock_t.h=0;lock_t.m=0;lock_t.s=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",s[i].ID,&s[i].in.h,&s[i].in.m,&s[i].in.s,&s[i].out.h,&s[i].out.m,&s[i].out.s);
		if(compare(unlock_t,s[i].in)){unlock_t=s[i].in;unlocked=i;}
		if(compare(s[i].out,lock_t)){lock_t=s[i].out;locked=i;}
	}
	cout<<s[unlocked].ID<<" "<<s[locked].ID<<endl;
	return 0;
}