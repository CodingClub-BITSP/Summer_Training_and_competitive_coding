#include <stdio.h>
#include <time.h>

int LinearSearch(int list[],int size,int key)
{
	//LoopCounter
    int i;
    //Looping through all elements untill it matches the key
    for (i=0; i<size; i++)
    {
    	//Checking if we meet the key
    	if(list[i]==key)
    		return i;
    }
    //If key is not in list, return -1
    return -1;
}

void main()
{
	//clock starts and end trackers
    clock_t start, end;
    //Size of the array
    int n;
    scanf("%d",&n);
    
    //Time used array for averaging time
    double time_used[n];
    
    //worst time complexity
    double worst_time;
    
    //Array of the numbers
    int A[n];
    
    //AverageTime
    double avg=0;
    
    //LoopCOunter
    int i;
    
    //Populating array (used input.txt)
    for (i=0;i<n;i++)
    {
    	scanf("%d",&A[i]);
    }
    
    //position of matching key
    int pos;
    
    //Prints Array
    for(i=0;i<n;i++)
    {
    	printf("%d, ",A[i]);
    }
    
    //Calculating time taken for n attempts and keys as Array[i]->Array[n-1]
    for (i=0; i<n; i++)
    {
    	//Timer Starts
        start = clock();
        //Search starts
        pos=LinearSearch(A, n, A[i]);
        //Timer Ends
        end=clock();
        //Populating time_used Array
        time_used[i] = ((double) (end - start)) / CLOCKS_PER_SEC;
        //Printing Where the key was found
        printf("\nKey found at %d\n",pos);
        //Time Taken
        printf("For size of array=%d, and key as the element no. %d it took %f secs to search\n",n,A[i],time_used[i]);
        //Adding the time to average value
        avg+=time_used[i];
    }
    //Average Time Taken
    avg = avg/n;
    printf("\nAvg time used is %f secs", avg);
    
    //Worst time complexity
        start = clock();
        //Used 100 as the key because none of my numbers is greater than 50, so 100 will never be in my any of the arrays
        //So will get the worst time complexity
        pos=LinearSearch(A, n, 100);
        end=clock();
        worst_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nFor size of array=%d, and key as 100, it took %f secs as the worst time to search\n",n,worst_time);
    
    
}
