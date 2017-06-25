#include<stdio.h>
#include<time.h>
void main()
{
	int key,c,comparisons;
	clock_t start, end;double time_reqd;
	FILE *fp;int n;int i;int k;
	FILE *fp1;
    printf("Enter size of array: 8 or 14 or 100: \n");//the test cases have sizes 8 , 14 ,100,i.e one has 8 nos and other 14
	scanf("%d",&n);//n stores the size of array
	int ls[n];//the list which stores the numbers read and where linear search would be performed

	if(n==8)
	{
		fp = fopen("TestCase0.txt","r");
		for (i = 0; i < 8; i++)
		{
        fscanf(fp, "%3d", &ls[i]);//reading each number from the file into the array
		}
	}
	else if(n==14)
	{
		fp = fopen("TestCase1.txt","r");
		for (i = 0; i < 14; i++)
		{
        fscanf(fp, "%3d", &ls[i]);//reading each number from the file into the array
		}
	}
	else if(n==100)
	{
		fp = fopen("TestCase2.txt","r");
		for (i = 0; i < 100; i++)
		{
        fscanf(fp, "%3d", &ls[i]);
		}
	}
	else
		printf("Wrong input");
	printf("Enter the key \n");
	scanf("%d",&key);//key to be searched

	printf("The array:\n");
	for(k=0;k<n;k++)
	{
		printf("%d,",ls[k]);
	}
	printf("\n");
	start = clock();
	for(i=0;i<n;i++)
	{
		comparisons++;
		if(key==ls[i])
		{
			printf("Key present at %d position",i+1);
			c=1;
			break;
		}
	}
	end = clock();
	time_reqd = ((double) (end - start)) / CLOCKS_PER_SEC;
	if(c==0)
	{
		printf("The number is not present\n");
	}
	printf("The time required for the algo:%f",time_reqd);
	fp1 = fopen("LinearAverage.txt","w");
	fprintf(fp1, "%d", comparisons);
 }
/*-----Complexity analysis----------
if arithmetic,logical operations are provided with 1 unit of execution time-
	In the above search iteration,
	T(n)= 2(n+1),for the case when search key not present or is at the end position,i.e. taking the worst case into consideration
	1 unit each for comparison and increment operation;n+1 times includes the false condition check as well;
	T(n)~n
	Time complexity is O(n) */

