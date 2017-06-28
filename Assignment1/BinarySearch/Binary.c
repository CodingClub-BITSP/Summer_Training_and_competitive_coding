/*# Algorithm

BinSearch(ls, key, lo, hi){

	mid = (hi - lo)/2;

	if(ls[mid] is equal to key){
		return mid;
	}else if(ls[mid] is greater than key){
		return BinSearch(ls, key, mid + 1, hi);
	}else{
		return BinSearch(ls, key, lo, hi - 1);
	}
}*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BinSearch(int list[], int key, int low, int high)
{
	int i;
	int mid ;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if (list[mid]==key)
			return mid;
		if (list[mid] > key)
		{
			high = mid-1;
		}
		
		if (list[mid] < key)
		{
			low = mid+1;
			//mid = low + (high-low)/2;
		}
	}	
	return -1;		
}


void main()
{
	//clock starts and end trackers
    clock_t start, end;
    //Size of the array
    int n,key, comp=0;
    scanf("%d",&n);
    
    //Time used array for averaging time
    double time_used[1000];
    
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
    
    
    
    time_t t;
 	srand((unsigned) time(&t));
 	
    //Calculating time taken for n attempts and keys as Array[i]->Array[n-1]
    for (i=0; i<1000; i++)
    {
        key = rand() % 10000;
    	//Timer Starts
        start = clock();
        //Search starts
        pos=BinSearch(A, key, 0, n-1);
        //Timer Ends
        end=clock();
        //Populating time_used Array
        time_used[i] = ((double) (end - start)) / CLOCKS_PER_SEC;
        //Printing Where the key was found
        if (pos!=-1)
            comp +=1;
        
        //Adding the time to average value
        avg+=100000*time_used[i];
    }
    //Average Time Taken
    avg = avg/n;
    printf("\nFor Size : %d, Avg time used was %f secs",n,avg);
    printf("\nFor Size : %d, No. of successes was %d.",n,comp);
    
    //Worst time complexity
        start = clock();
        //Used 10001 as the key because none of my numbers is greater than 10000, so 10001 will never be in my any of the arrays
        //So will get the worst time complexity
        pos=BinSearch(A, 10001, 0, n-1);
        end=clock();
        worst_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        worst_time*=100000;
        printf("\nFor size of array=%d, and key as 10001, it took %f secs as the worst time to search\n",n,worst_time);
    
    
    //Prints Array
    printf("Array \n [ ");
    for(i=0;i<n-1;i++)
    {
    	printf("%d, ",A[i]);
    }
    printf("%d ] ",A[n-1]);
    
}
			
		


