#include<stdio.h>
#include<stdlib.h>
int size,capacity;

int* allocations()//to double the size of array when 90% is filled
{
	int *reallocate = (int*)malloc((2*capacity)*sizeof(int));
	return reallocate;
}
int* deallocations()//to double the size of array when 90% is filled
{
	int *deallocate = (int*)malloc((capacity/2)*sizeof(int));
	return deallocate;
}
int* add(int *arr1)//add numbers into the list
{
	int *temp;int i;
	printf("Enter number to add\n");
	scanf("%d",&(*(arr1+size)));
	size++;

	int percent =(size/capacity);
	if(percent>0.9)
	{
		temp=allocations();//temp stores the new array after doubling
		capacity=capacity*2;
		for(i=0;i<size;i++)
		{
			*(temp+i)= *(arr1+i);//copying the contents of original array

		}
		return temp;
	}
	else if(percent<0.4)
	{
		temp=deallocations();//temp stores the new array after doubling
		capacity=capacity/2;
		for(i=0;i<size;i++)
		{
			*(temp+i)= *(arr1+i);//copying the contents of original array
		}
		return temp;
	}
	else
		return arr1;
}
int* delete(int *delete)
{
	int *new1;int l;
	size--;

	int percent1 =(size/capacity);
	if(percent1>0.9)
	{
		new1=allocations();
		capacity=capacity*2;
		for(l=0;l<size;l++)
		{
			*(new1+l)= *(delete+l);
		}
	}
	else if(percent1<0.4)
	{
		new1=deallocations();
		capacity=capacity/2;
	    for(l=0;l<size;l++)
		{
			*(new1+l)= *(delete+l);
		}
	}
	else
	{
		new1=(int*)malloc(capacity*sizeof(int));
		for(l=0;l<size;l++)
		{
			*(new1+l)= *(delete+l);
		}
	}
	return new1;

}

void main()
{

	int *arr;char ch;int *temp1;
	arr = (int*)malloc(2*sizeof(int));
	capacity=1;
	size=0;
	temp1=arr;
	while(ch!='e')
	{
	printf("The array is of capacity 1 initially.To add-a.To delete-d.To exit-e\n");
	scanf(" %c",&ch);
	if(ch=='a')
	{
		temp1=add(temp1);
		printf("Array after addition:\n");int j;
		for(j=0;j<size;j++)
		{
			printf("%d,",*(temp1+j));
		}
	}
	if(ch=='d')
	{
		temp1=delete(temp1);
		printf("Array after deletion:\n");int j;
		for(j=0;j<size;j++)
		{
			printf("%d,",*(temp1+j));
		}
	}
	}
}
