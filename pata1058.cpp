/*
http://pat.zju.edu.cn/contests/pat-a-practise/1058

1058. A+B in Hogwarts (20)

If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
*/

#include<stdio.h>
int main()
{
  int a1,b1,a2,b2,a3,b3,c1,c2,c3;
  scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
  a3=b3=c3=0;
  c3=c1+c2;
  if(c3>=29){c3-=29;b3=1;}
  b3+=b1+b2;
  if(b3>=17){b3-=17;a3=1;}
  a3+=a1+a2;
  printf("%d.%d.%d\n",a3,b3,c3);
  return 0;
}