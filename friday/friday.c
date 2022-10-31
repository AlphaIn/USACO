/*
ID: linxuan4
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void main () 
{
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
	int days_in_months_unleap[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int days_in_months_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int pre_13 = 0;
	int cur_13 = 0;
	int times_13[7];
	memset(times_13, 0 , 7*sizeof(int));
	int N = 0;
	fscanf (fin, "%d", &N);
	int i = 0, j = 0;
	for(i = 0 ; i < N; i++)
	{
		for(j = 0 ; j < 12; j++)
		{
			if(i == 0 && j == 0)
			{
			   cur_13 = 6;
			}
		    else
			{
			if(((1900+i)%4 == 0 && (1900 + i) % 100 != 0) || (1900+i)%400 == 0)
			{
			   cur_13 = (days_in_months_leap[(j-1) >= 0 ? (j-1) : 11]-(7-pre_13)) % 7;
			}
			else
			{
			   cur_13 = (days_in_months_unleap[(j-1) >= 0 ? (j-1) : 11]-(7-pre_13)) % 7;
			}
			}
                     if(cur_13 == 0)
                     {
                        cur_13 = 7;
                     }
			times_13[cur_13 - 1] += 1;
            pre_13 = cur_13;
            cur_13 = -1;
		}
	}
   fprintf (fout, "%d %d %d %d %d %d %d\n", times_13[5], times_13[6], times_13[0],times_13[1], times_13[2], times_13[3], times_13[4]);
   exit (0);
}
