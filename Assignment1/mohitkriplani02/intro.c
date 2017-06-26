#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned long int i=1;
    while(1)
    {
        int *arr;
        arr=(int*)malloc(i*sizeof(int));//dynamic memory allocated using malloc
        if(arr==NULL)
        {
            printf("Error:i max value is %d",i*4/1024/1024/1024);
             return 0;
        }

        i*=2;
        free(arr);
    }
}
