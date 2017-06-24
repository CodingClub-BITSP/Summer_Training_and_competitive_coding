#include <stdio.h>
#include <stdlib.h>

int size_of_ram(int, int);

void main()
{
	int size = 0;
	size = size_of_ram(1073741824,size);               //1 GB = 1073741824 = 1024*1024*1024 bytes
	printf("%d\n",size );

}



int size_of_ram(int x, int size)
{	
	
	while(1)
	{
		char *ch = (char*) malloc(x*sizeof(char));
		if(x==1)
		{
			return size;
		}
		else if(ch == NULL)
		{
			x = x/2;
			size_of_ram(x);
		}
		else
		{
			size = size + x;
		}
	}
}
