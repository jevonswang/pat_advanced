/*
http://pat.zju.edu.cn/contests/pat-a-practise/1033

1033. To Fill or Not to Fill (25)

With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/

#include<stdio.h>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct Station{
	double D;
	double P;
}station[1000];

bool cmp(Station a,Station b){
	return a.D < b.D;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\input.txt","r",stdin);

	int C_max, N;          //capacity and gas station numbers
	double D_avg;         //D_avg means distance per unit gas that the car can run,
	double D_max;		  //D_max means the farthest distance a car can run with full gas
	double D_tot;	      //D_tot means the distance between destination and hangzhou 
	double D_remain = 0;	//the gas remain after last stage
	double cost = 0;		//Current cost
	int i, j;
	int pos = 0;          //Current position

	scanf("%d %lf %lf %d", &C_max, &D_tot, &D_avg, &N);
	for (i = 0; i<N; i++)
		scanf("%lf %lf", &station[i].P, &station[i].D);

	station[N].D = D_tot;// the farthest position should be the destination

	
	
	sort(station,station+N,cmp);
	//qsort(station, N + 1, sizeof(Station), cmp);


	//use quick sort to sort the gas station in increasing order by distance

	D_max = C_max*D_avg;

	if (station[0].D != 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	//if the first gas station is not at the start point, we cannot start



	while (1)//the main loop
	{
		if (station[pos].D + D_max<station[pos+1].D)
		{
			printf("The maximum travel distance = %.2lf\n", station[pos].D + D_max);
			return 0;
		}
		//if fill gas full,still cannot go to the next station,print out the maximum distance

		//find the closest station with price cheaper than current one
		for (i = pos; i<N && (station[i].D - station[pos].D <= D_max);i++)
			if (station[i].P<station[pos].P){
				if (D_remain >= station[i].D - station[pos].D)	D_remain -= station[i].D - station[pos].D;
				else{   //it is not enough to go to that station with gas remain
				
					cost += (station[i].D - station[pos].D - D_remain) / D_avg*station[pos].P;
					D_remain = 0;
				}
				pos = i;
				break;
			}
		if (i == N && (station[i].D - station[pos].D <= D_max)){ //can not find the cheaper one with full gas and we can reach the destination 
			if (D_remain<station[i].D - station[pos].D)
				cost = cost + (station[i].D - station[pos].D - D_remain) / D_avg*station[pos].P;
			printf("%.2lf\n", cost);
			return 0;
		}
		if (i<N && (station[i].D - station[pos].D>D_max)){ //station[pos].P is the most cheapest in the distance that a full gas car can reach 
			cost = cost + (D_max - D_remain) / D_avg*station[pos].P;//update cost;
			D_remain = D_max - station[pos+1].D + station[pos].D;//update D_remain
			pos++;//go to the next gas station
		}


	}

	return 0;
}
