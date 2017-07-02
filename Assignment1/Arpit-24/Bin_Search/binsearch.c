#include<stdio.h>
#include<time.h>

int cmp=0;
clock_t start_t, end_t;
double total_t, tot_time=0;

void binsearch(int list[], int key, int lo, int hi)
{
    int mid;
    start_t = clock();
    while(lo<=hi)
    {
        mid=(hi+lo)/2;
        if(++cmp&&list[mid]==key)
        {
            end_t = clock();
            return;
        }
        else if(list[mid]>key)
            hi=mid-1;
        else
            lo=mid+1;
    }
    end_t=clock();
}

int main()
{
    int i, list[10000], key;
    for(i=0;i<10000;i++)
        scanf(" %d",&(list[i]));
    for(i=0;i<10000;i++)
    {
        scanf(" %d",&key);
        binsearch(list,key,0,9999);
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        tot_time+=total_t;
    }
    printf("Total time for 10000 times loop run = %lfs\n",tot_time);
    printf("\nAvg. time for 10000 times loop run = %lfs\n",tot_time/10000);
    printf("\nAvg. No. of comparisons made : %d",cmp/10000);
    return 0;
}