#include<stdio.h>
#include<time.h>
#include<stdlib.h>

clock_t start_t,end_t;
double total_t;

int main()
{
    long long int size=1;
    start_t=clock();
    while(1)
    {
        int *memory=(int *)malloc(size*sizeof(int));
        if(memory==NULL)
            break;
        free(memory);
        size*=2;
    }
    end_t=clock();
    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("Memory Available for use to you is : %d GB(s)",size*sizeof(int)/(1024*1024*1024));
    printf("\n\nTIme taken is : %lf seconds",total_t);
    return 0;
}