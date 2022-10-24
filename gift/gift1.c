/*
ID: linxuan4
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int arr_pos(char (*src)[14], int m, char *dst)
{
    int arr_pos = -1;
    int j = 0;
    for(j = 0; j < m; j++)
    {
        if(strcmp(src[j],dst) == 0)
            arr_pos = j;
    }
    return arr_pos;
}

void main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    char a[10][14];
    char div_list[14];
    int account[10];
    int np;
    int i = 0;
    memset(a,0,sizeof(a));
    memset(div_list,0,sizeof(div_list));
    memset(account,0,10*sizeof(int));
    fscanf (fin, "%d", &np);
    for(i = 0; i < np; i++)
    {
      fscanf(fin,"%s", a[i]);
    }
   for(i = 0; i < np; i++)
   {
       int div_money = 0;
       int div_num = 0;
       int giv_pos = -1;
       int giv_num = 0;
       int left = 0;
       fscanf (fin, "%s %d %d", div_list, &div_money, &div_num);
       giv_pos = arr_pos(a, np, div_list);
       if(div_num > 0)
       {
           giv_num = div_money / div_num;
           left = div_money % div_num;
           account[giv_pos] -= div_money;
           account[giv_pos] += left;
           int j = 0;
           char div_tmp[div_num][14];
           memset(div_tmp,0,sizeof(div_tmp));
           for(j = 0; j < div_num; j++)
           {
               fscanf (fin, "%s", div_tmp[j]);
               int rev_pos = -1;
               rev_pos = arr_pos(a, np, div_tmp[j]);
               account[rev_pos] += giv_num;
           }
       }
   }
  for(i = 0; i < np ; i++)
  {
      fprintf(fout,"%s", a[i]);
      fprintf(fout, " ");
      fprintf(fout, "%d\n", account[i]);
  }
    exit (0);
}
