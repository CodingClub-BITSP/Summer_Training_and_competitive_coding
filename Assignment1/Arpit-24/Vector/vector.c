#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int size=8,max_size=10;
clock_t start_t, end_t;
double tot_t;

int* replace(int *vector);

int* add(int *vector)
{
    int num;
    printf("\n\nEnter Number to add : ");
    scanf(" %d",&num);
    start_t=clock();
    vector[size++]=num;
    end_t=clock();
    tot_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\n\nTime taken for Addition is %lfs\n",tot_t);
    if(((float)size/max_size)>0.89)
    {
        max_size*=2;
        vector=replace(vector);
    }
    printf("\nNew Vector : ");
    view(vector);
    return vector;
}

int* del(int *vector)
{
    start_t=clock();
    vector[--size]=1000;
    end_t=clock();
    tot_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\n\nTime taken for Deletion is %lfs\n",tot_t);
    if(((float)size/max_size)<0.4)
    {
        max_size/=2;
        replace(vector);
    }
    printf("\nNew Vector : ");
    view(vector);
    return vector;
}

int* replace(int *vector)
{
    int *new_vector;
    int i;
    new_vector=(int *)malloc(sizeof(int)*max_size);
    for(i=0;i<size;i++)
    {
        new_vector[i]=vector[i];
    }
    free(vector);
    end_t=clock();
    tot_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("\nTime taken for Replacement is %lfs\n",tot_t);
    return new_vector;
}

void view(int *vector)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",vector[i]);
}

int main()
{
    char option;
    int *vector=(int *)malloc(sizeof(int)*max_size);
    vector[0]=16;
    vector[1]=13;
    vector[2]=62;
    vector[3]=81;
    vector[4]=95;
    vector[5]=39;
    vector[6]=99;
    vector[7]=18;
    do
    {
        printf("\n\nWhat would you like to do? (A-Add,D-Delete,V-View,E-Exit) : ");
        scanf(" %c",&option);
        switch(option)
        {
            case 'a':
            case 'A':
                vector=add(vector);
                break;
            case 'd':
            case 'D':
                vector=del(vector);
                break;
            case 'v':
            case 'V':
                view(vector);
                break;
            case 'e':
            case 'E':
                printf("\nThank You!!");
                break;
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }while(option!='e'||option=='E');
    return 0;
}