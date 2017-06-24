#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 int* ptr;
 int i;
 i=0;
 int r;
 r=1;
 while(i!=1)
 {
  ptr= (int) malloc(sizeof(int)*r);
  if(ptr==NULL)
   {i=1;
    ptr= (int) malloc((r-1)*sizeof(int));
    }
    r++;
    }
  int k;
  k= sizeof(ptr);
    printf("Max size is %d" , k);
    }   
