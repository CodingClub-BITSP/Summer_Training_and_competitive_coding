#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
sizeof vector is by default 1*sizeof(int)
*/

typedef struct vector
{
	int size;
	int *arr;
	int capacity;
} vector;

int check_size(vector *v)
{
	if((sizeof(*(v->arr)) <= (0.09*(v->capacity))) && (sizeof(*(v->arr)) >= (0.04*(v->capacity))))
		return 1;
	else
		return 0;
}

int main()
{
	int i;
	int *temp;
	vector *v = malloc(sizeof(vector));
	v->size = 1;                                                    //by default
	v->capacity = 10;
	v->arr = malloc((v->size)*sizeof(int));
	for(int i = 0;i<6;i++)
	{
		v->arr[i] = i;
	}
	printf("Start entering options");
	
	while(1)
	{	
		scanf("%d",&i);
		printf("IN WHILE\n");
		switch(i)
		{
			printf("1.Add element\n2.Delete element\n");
			case 1:                                                         //add element
				if(check_size(v))
				{
					printf("IN");
					scanf("%d",&((v->arr)[(v->size)-1]));
					(v->size)++;
				}
				else
				{
					scanf("%d",&((v->arr)[(v->size)-1]));
					v->capacity *= 2;
					temp = malloc(v->capacity);
					printf("size doubled\n");
					for(int i = 0;i<(v->size);i++)
					{
						temp[i] = (v->arr)[i];
					}
					free(temp);
					(v->size)++;
				}
				break;
			case 2:                                                        //delete element
				if(check_size(v))
				(v->size)--;
				else
				{
					v->capacity /= 2;
					temp = malloc(v->capacity);
					printf("size halved\n");
					for(int i = 0;i<(v->size)-1;i++)
					{
						temp[i] = (v->arr)[i];
					}
					free(temp);
					(v->size)--;
				}
				break;
		}
	}
}
