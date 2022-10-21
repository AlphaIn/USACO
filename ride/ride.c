/*
ID: linxuan4
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(char arr[])
{
   int sum = 1;
   int i = 0;
   for(i = 0; i < strlen(arr) && isalpha(arr[i]); i++)
  {
       sum *= arr[i] - 64;
   }
   return (sum%47);
}
void main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    int sum1,sum2;
    char a[8],b[8];
    fscanf (fin, "%s %s", a,b);
    sum1 = cmp(a);
    sum2 = cmp(b);
    if(sum1 == sum2)
      fprintf (fout, "%s\n", "GO");
    else
      fprintf (fout, "%s\n", "STAY");
    exit (0);
}
