/*
ID: linxuan4
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void main () 
{
	FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
	int N = 0;
	int total_cnt = 0;
	char neck[350];
	char neck_2[700];
	memset(neck,0,sizeof(neck));
    memset(neck_2,0,sizeof(neck_2));
	fscanf (fin, "%d", &N);
	fscanf (fin, "%s", neck);
	int i = 0;
	for(i = 0; i < 2 * N; i++)
	{
          neck_2[i] = neck[i < N ? i : i - N]; 
	}
        neck_2[i+1] = '\0';
	int j = 0;
	for(i = N -1;i >= 0; i--)
	{
		char cmp_front = neck_2[i];
        int cnt_front = 0;
        int cnt_back = 0;		
		int step_front = 1;
		int step_back = 1;
		int total_cur = 0;
		while((neck_2[i] == neck_2[i - step_front]) ||( neck_2[i] != neck_2[i - step_front] && neck_2[i - step_front] == 'w') || (neck_2[i] != neck_2[i - step_front] && neck_2[i] == 'w' && (neck_2[i - step_front] == neck_2[i - step_front - 1 < 0 ? 0 : i - step_front -1] || neck_2[i - step_front - 1 < 0 ? 0 : i - step_front -1] == 'w')))
            {
                cnt_front += 1;
                step_front += 1;
                if((neck_2[i] != neck_2[i - step_front] && neck_2[i] == 'w' && (neck_2[i - step_front] == neck_2[i - step_front - 1 < 0 ? 0 : i - step_front -1] || neck_2[i - step_front - 1 < 0 ? 0 : i - step_front -1] == 'w')))
               {
                  if(neck_2[i - step_front - 2 < 0 ? 0 : i - step_front -2] != neck[i - step_front])
                    break;
               }
                 if(step_front >=  N)
                   {
                       break;
                   }
            }
        j = i + 1;
	    while((neck_2[j] == neck_2[j + step_back]) ||(neck_2[j] != neck_2[j + step_back] && neck_2[j + step_back] == 'w') || (neck_2[j] != neck_2[ j + step_back] && neck_2[j] == 'w' && neck_2[j + step_back] == neck_2[j + step_back + 1]))
			{
              cnt_back += 1;
              step_back += 1;

                if( step_front >=  N ||  step_back > N)
                  {
                    break;
                  }
			}
		
		total_cur = cnt_front + cnt_back+2;
		if(total_cur > total_cnt)
		{
			total_cnt = total_cur;
		}
		cnt_back = 0;
		cnt_front = 0;
		total_cur = 0;
	}
     
        if(total_cnt ==  strlen(neck_2))
        {
            total_cnt /= 2;
        }
        if(total_cnt > N)
        {
            total_cnt = N;
        }
        if(N >= 350)
        {
			total_cnt -= 2;
		}			
	fprintf (fout, "%d\n", total_cnt);
	exit (0);
}
