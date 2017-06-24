#include <stdio.h>
#include <stdlib.h>

int size_of_ram(int, int);

void main()
{
	int size = 0;
	int t = size_of_ram(1048576,size);
	printf("%d\n",t );

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
