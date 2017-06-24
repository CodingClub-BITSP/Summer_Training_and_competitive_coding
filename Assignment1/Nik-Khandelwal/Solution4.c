#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int size;
	int capacity;
}vector;

void add(vector *v,int);
void delete(vector *v);
void maintain(vector *v);

void main()
{
	int i,k;
	vector v;
	v.data = (int*)malloc(5*sizeof(int));
	for(i = 0;i< v.capacity ;i++)
	{
		v.data[i] = 0;
	}										//initializing with random values just for testing purposes
	v.data[0] = 2;
	v.data[1] = 78;
	v.data[2] = 23;
	v.size = 3;
	v.capacity = 5;
	printf("Current List\n");
	for (i = 0; i < v.size; i++)
	{
		printf("%d\n",v.data[i] );
	}
	printf("Size of the list is %d and total capacity of the list is %d\n",v.size,v.capacity);

	printf("Enter 'd' to delete the last element and 'a' to add to the list ");
	char ans;
	scanf("%c",&ans);

	if(ans == 'd' || ans =='D')
	{
		delete(&v);
		printf("Enter 'd' to delete the last element and 'a' to add to the list ");
		scanf("%c",&ans);

	}
	if(ans == 'a' || ans == 'A')
	{
		printf("Enter no of element to add\n");
		int n;
		scanf("%d",&n);
		int e[n];

		for(k = 0;k< n;k++)
		{
			printf("Enter element no: %d",k+1);
			scanf("%d",&e[k]);
			add(&v,e[k]);
		}
		printf("Enter 'd' to delete the last element and 'a' to add to the list ");
		scanf("%c",&ans);
	}


}

void add(vector *v,int e)
{
	int i;	
	v->data[v->size] = e;
	v->size += 1;
	maintain(v);

	printf("The updated list:\n");
	for(i =0; i< (v->size); i++)
		printf("%d\n",v->data[i]);
	printf("Size of the list is %d and total capacity of the list is %d\n\n",v->size,v->capacity);
}

void delete(vector *v)
{	
	int i;
	v->data[v->size-1] = 0;
	v->size -= 1;
	maintain(v);
	printf("The updated list:\n");
	for(i =0; i< (v->size); i++)
		printf("%d\n",v->data[i]);
	printf("Size of the list is %d and total capacity of the list is %d\n",v->size,v->capacity);
} 

void maintain(vector *v)
{	
	int i;
	if(v->size > 0.9*v->capacity)
	{
		vector v2;
		v2.data = (int*)malloc(2*v->capacity*sizeof(int));
		for(i=0;i<v->size;i++)
			v2.data[i] = v->data[i];
		v2.size = v->size;
		v2.capacity = 2*v->capacity;
		free(v->data);
		*v = v2;
	}
	if(v->size < 0.4*v->capacity)
	{
		vector v2;
		v2.data = (int*)malloc(0.5*v->capacity*sizeof(int));
		for(i = 0; i < v->size; i++)
			v2.data[i] = v->data[i];
		v2.size = v->size;
		v2.capacity = 0.5*v->capacity;
		free(v->data);
		*v = v2;
	}

}
