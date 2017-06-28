#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
int size = 10;
time_t t;
srand((unsigned)time(&t));
//int search;
//scanf("%d",&search);
clock_t start,end_t;
float time_used;
int arr[size];
FILE* fp = fopen("bin_search.txt","w");
for(int i = 0;i<size;i++)
{
	arr[i] = i;
}
int beg = 0,end = size -1,mid = (beg + end)/2;
for(int i = 0;i<1000;i++)
{
start = clock();
int search = rand()%100;
while((beg<=mid) && (mid != search))
{
	if(search == arr[mid])
	break;
	else if(search>arr[mid]) 
	{
		beg = mid + 1;
		mid = (beg + end)/2; 
	}
	else 
	{
		end = mid - 1;
		mid = (beg + end)/2;
	}
}
end_t = clock();
time_used = (float)(end_t - start)/CLOCKS_PER_SEC;
fprintf(fp,"%f",time_used);
fprintf(fp,"%c",'\n');
}
}
