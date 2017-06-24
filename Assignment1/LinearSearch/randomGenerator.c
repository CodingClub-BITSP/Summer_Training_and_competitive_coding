#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, n;
   time_t t;
   scanf("%d",&n);
   int A[n];
   int j;
   srand((unsigned) time(&t));
   for( i = 0 ; i < n ; i++ ) 
   {
      A[i] = rand() % 50;
   }
	
    printf("%d\n");
   for( i = 0 ; i < n ; i++ ) 
   {
      printf("%d\n",A[i]);
   }
   
   return(0);
}
