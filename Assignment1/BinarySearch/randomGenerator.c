#include <stdio.h>
#include <stdlib.h>

void Sort(int A[],int size)
{
	int i,j,a;
	for (i = 0; i < size; ++i)
    	{
            for (j = i + 1; j < size; ++j)
            {
                if (A[i] > A[j])
                {
                    a =  A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
    }
}


void main()
{
    int i, j, a, n;
 
 	time_t t;
 	srand((unsigned) time(&t));
 	//A[i] = rand() % 50;
 	
 	
    ///printf("Enter the value of N \n");
    scanf("%d", &n);
    int A[n];
    //printf("Enter the numbers \n");
    for (i = 0; i < n; ++i)
        A[i]=rand() % 10000;
    
    Sort(A,n);
    printf("%d\n",n);
    for (i = 0; i < n; ++i)
        printf("%d\n", A[i]);
}
