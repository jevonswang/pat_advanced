/*
http://pat.zju.edu.cn/contests/pat-a-practise/1016


1016. Phone Bills (25)

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record{
	int month;
	char name[21];
	int day;
	int hour;
	int minute;
	char onOff;
	int total;
} records[1000];

int n;
int fee[24];

int compare(const void *a, const void *b) //qsort is customed to support complicated sort!
{
	record *rA = (record *)a;
	record *rB = (record *)b;

	int result = strcmp(rA->name, rB->name);
	if (result < 0) return -1;
	else if (result > 0)return 1;
	else return rA->total - rB->total;
}

double charge(record start, record end)
{
	int sday, shour, sminute, eday, ehour, eminute;
	sday = start.day;
	shour = start.hour;
	sminute = start.minute;
	eday = end.day;
	ehour = end.hour;
	eminute = end.minute;

	double cost = 0;
	long time = 0;

	while (sday < eday)//先让天相等
	{
		time += (60 - sminute);
		cost += (60 - sminute) * fee[shour];
		sminute = 0; shour++;//分化成0，时加1
		time += 60 * (24 - shour);
		while (shour < 24)
		{
			cost += 60 * fee[shour];
			shour++;
		}
		shour = 0; sday++;//时化成0，天加1
	}//天此时相等，时分为00:00
	while (shour < ehour)//再让时相等
	{
		time += (60 - sminute);
		cost += (60 - sminute) * fee[shour];
		sminute = 0; shour++;
	}

	time += (eminute - sminute);
	cost += fee[ehour] * (eminute - sminute);

	printf("%02d:%02d:%02d %02d:%02d:%02d %ld $%.2f\n", start.day, start.hour, start.minute, end.day, end.hour, end.minute, time, cost / 100);

	return cost;
}

int main()
{
	freopen("C:\\Users\\Administrator\\Desktop\\input.txt", "r", stdin);


	for (int i = 0; i != 24; ++i)
		scanf("%d", &fee[i]);
	scanf("%d", &n);
	for (int i = 0; i != n; i++){
		record r;
		char tmp[21];
		scanf("%s %d:%d:%d:%d %s", r.name, &r.month, &r.day, &r.hour, &r.minute, tmp); //Take care of the r.name, instead of &r.name
		r.total = r.day * 24 * 60 + r.hour * 60 + r.minute;
		r.onOff = tmp[1];
		records[i] = r;
	}

	qsort(records, n, sizeof(record), compare);

	double amount = 0;
	bool hasOutputName = false;
	bool waitForOn = true;
	record onRecord;
	int month;
	char currentName[21];

	for (int i = 0; i != n; ++i) {
		record r = records[i];
		if (i == 0 || strcmp(currentName, r.name) != 0) {
			if (i != 0 && hasOutputName) { //注意后面这个条件。
				printf("Total amount: $%.2f\n", amount / 100);
			}

			strcpy(currentName, r.name);
			month = r.month;
			hasOutputName = false;
			waitForOn = true;
			amount = 0;
			onRecord = r;
		}

		if (waitForOn) {
			if (r.onOff == 'n'){
				waitForOn = false;
				onRecord = r;
			}
		}
		else {
			if (r.onOff == 'f') {
				if (!hasOutputName){
					hasOutputName = true;
					printf("%s %02d\n", currentName, month);
				}
				amount += charge(onRecord, r);
				waitForOn = true;
			}
			else {
				onRecord = r;
			}
		}
	}

	if (hasOutputName)
		printf("Total amount: $%.2f", amount / 100);

	return 0;
}
