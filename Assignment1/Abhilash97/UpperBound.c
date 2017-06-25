#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *arr;
    arr = (int*)malloc(2*(sizeof(int)));
    int k=2;int sum=(sizeof(int))*k;
	while(arr!=NULL)
	{
		k*=2;
		arr=(int*)malloc(k*(sizeof(int)));
		free(arr);//sum=sum+(sizeof(int))*k;
	}
	printf("%d\n",k);
	printf("%d\n",(sizeof(int))*k);
	//printf("%d",sum);
}
//returns 2GB;
//Using realloc()
/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pa = malloc(10 * sizeof *pa); // allocate an array of 10 int
    if(pa) {
        printf("%zu bytes allocated. Storing ints: ", 10*sizeof(int));
        for(int n = 0; n < 10; ++n)
            printf("%d ", pa[n] = n);
    }

    int *pb = realloc(pa, 1000000 * sizeof *pb); // reallocate array to a larger size
    if(pb) {
        printf("\n%zu bytes allocated, first 10 ints are: ", 1000000*sizeof(int));
        for(int n = 0; n < 10; ++n)
            printf("%d ", pb[n]); // show the array
        free(pb);
    } else { // if realloc failed, the original pointer needs to be freed
        free(pa);
    }
}*/
