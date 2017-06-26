#include<stdio.h>
#include<time.h>
void main()
{
	int hi,lo,key;int c;int mid;int n;char ch;int x;
	clock_t start,end;double time_reqd;
	int comparisons;
	FILE *fp;int i;
	FILE *fp1;
	printf("Enter size of array: 8 or 14 or 100: \n");//the test cases have sizes 8 , 14 ,100,i.e one has 8 nos and other 14
	scanf("%d",&n);//n stores the size of array
	int ls[n];//the list which stores the numbers read and where binary search would be performed

	if(n==8)
	{
		fp = fopen("TestCase0.txt","r");
		for (i = 0; i < 8; i++)
		{
        fscanf(fp, "%3d", &ls[i]);
		}
	}
	else if(n==14)
	{
		fp = fopen("TestCase1.txt","r");
		for (i = 0; i < 14; i++)
		{
        fscanf(fp, "%3d", &ls[i]);
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
	lo = 0; hi = n-1;
	start = clock();
	while(lo<=hi)
	{
		comparisons++;
		mid = (lo+hi)/2;//line 1
		if(key==ls[mid])//line 2
		{
			c=1;
			break;
		}
		else if(key<ls[mid])//line 3
		{
			hi = mid-1;
		}
		else
		{
			lo=mid+1;
		}

	}
	end = clock();
	time_reqd = ((double) (end - start)) / CLOCKS_PER_SEC;
	int k=0;
	printf("The array:\n");
	for(k=0;k<n;k++)
	{
		printf("%d,",ls[k]);
	}
	printf("\n");
	if(c==0)
	{
		printf("The number is not present\n");
	}
	else
		printf("It is present at %d position\n",mid+1);

		printf("The time required for the algo:%f",time_reqd);
	fp1 = fopen("BinaryAverage.txt","w");
	fprintf(fp1, "%d", comparisons);
}
/*------Time Complexity analysis------
if arithmetic,logical operations are provided with 1 unit of execution time-
	In the binary search iteration,
	T(n)=T(n/2)+6;Considering the worst case, when either key is not present or it is present at the end or at the beginning,so
	ignoring line 2;
	6 units = 3 units for line 1, 1 unit for comparison in line 3 and 2 units for assignment and '+/-' inside line 2
	T(n/2)=T(n/4) + 6
	T(n)= T(n/4) + 6 + 6
	.....
	T(n)=T(n/2^k) + 6k
	   or
	T(n)=T(n/2^k) + Ck, C is a constant----(1)
	Worst case-when the iteration reduced the array to a single element ,i.e towards the end of the iteration
	=>n/2^k = 1;
	=>2^k = n;
	=> k = log(n) with base 2
	Now (1) => T(n)=T(1) + Ck;
	=> T(n)=T(1) + Clog(n);
	T(1) = C', where C' is some constant unit, as there would be only 1 iteration
	Therefore, T(n)=C'+Clog(n);
	T(n) directly proportional to log(n)
	Time complexity for such a function is O(log(n));
*/


