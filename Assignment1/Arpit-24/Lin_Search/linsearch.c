#include<stdio.h>
#include<time.h>

int cmp=0;
clock_t start_t, end_t;
double total_t, tot_time=0;

int Linsearch(int list[],int size,int key)
{
    int i;
    start_t = clock();
    for(i=0;i<size-i;i++)
    {
        if(++cmp&&list[i]==key)
        {
            end_t = clock();
            return i;
        }
        else if(++cmp&&list[size-i-1]==key)
        {
            end_t = clock();
            return size-i-1;
        }
    }
    end_t = clock();
    return -1;
}

int main()
{
    int i,value,key;
    int list[10000];
    for(i=0;i<10000;i++)
        scanf(" %d",&(list[i]));
    for(i=0;i<10000;i++)
    {
        scanf(" %d",&key);
        value=Linsearch(list,10000,key);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        tot_time+=total_t;
    }
    printf("Total time for 10000 times loop run = %lfs\n",tot_time);
    printf("\nAvg. time for 10000 times loop run = %lfs\n",tot_time/10000);
    printf("\nAvg. No. of comparisons made : %d",cmp/10000);
    return 0;
}