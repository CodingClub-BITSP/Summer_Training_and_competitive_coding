/*
This program will generate random numbers from 1 to size and feed it to a file. We can use this file as a test case for solutions1.c 
*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main()
{
FILE* fp;
fp = fopen("10.txt","w");
time_t t;
srand((unsigned)time(&t));
for(int i = 0;i<10;i++)
{
	fprintf(fp,"%d",rand()%100);
	fprintf(fp,"%c",'\n');
}

}
