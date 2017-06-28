/*
*The worst case time complexity should be O(n) as the worst case corresponds to having to search through every term before reaching to the l*ast element.
*Average is not correct might 
*
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float average(FILE *pointer)
{
float avg = 0;
float i;
	while(!feof(pointer))
	{
		avg += fscanf(pointer,"%f",&i);
	}
	avg /= 1000;
}

int main()
{
FILE *fp1 = fopen("10.txt","r");                 //pointer for iterating the search terms
FILE *fp2 = fopen("10.txt","r");                 //pointer for iterating through array for searching
FILE *rp = fopen("10_stats.txt","w");           //pointer for writing the run time in 10_stats
FILE *av_p = fopen("10_stats.txt","r");
clock_t start,end;
float time_spent;
int i = 0,j = 0;
for(int k = 0;k<1000;k++)
{
while(!feof(fp2))
{	fscanf(fp2,"%d",&j);
	start = clock();
	while(!feof(fp1))
	{	
		fscanf(fp1,"%d",&i);
		if(j == i)
		{
			printf("number found");
			break;
		}
		else
		{
			fscanf(fp1,"%d",&i);
			//printf("%d\n",i);
		}
	}
	end = clock();
time_spent = (float)(end - start)/CLOCKS_PER_SEC;
fprintf(rp,"%f",time_spent);
fprintf(rp,"%c",'\n');
}
fseek(fp2,0,SEEK_SET);
}
printf("Average is %f",average(av_p));
//printf("%f",time_spent);
}
