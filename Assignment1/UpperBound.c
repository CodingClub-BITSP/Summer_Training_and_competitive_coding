#include <stdio.h>
#include <stdlib.h>

void main()
{
    //initialising pointer
    int * ptr;
    // len : it is equal to twice the size of int
    int len=2*sizeof(int);
    //Dynamically allocating memory to the pointer
    ptr = (int*)malloc(len);
    // prev_len keeps the copy of the len before len becomes negative
    int prev_len;
    //Checking when len becomes negative or in other words croses the int max limit...
    //could have used while(ptr!=NULL) too and use len instead of lt, but then the program won't show...
    //the max int size
    while(len>0)
    {
        prev_len=len;
        // printing len, address of pointer and checking whether the pointer became null or not
        printf("Current Size of ptr is %d,\t\t address is %u, \tand is ptr==NULL? : %d\n",len, ptr ,ptr==NULL);
        //doubling size
        len*=2;
        // Reallocating twice the previous memory to pointer till it becomes null
        ptr=(int*)realloc(ptr,len);
    }
    //converting to GBs
    int ram_size=prev_len/(1024*1024*1024);
    //Multiplying by the sizeof(int).
    ram_size = sizeof(int)*ram_size;
    //Printing size of the ram
    printf("\nThe Size of your RAM should be %d GB\n",ram_size);
}
