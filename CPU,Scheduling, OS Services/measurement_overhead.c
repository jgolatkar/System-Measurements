/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Measurement Overhead 
*/


#include<stdio.h>
#include<time.h>

#define LOOP_COUNT 1000000
#define NANOSECONDS 1000000000


/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


int main(){
	
	struct timespec start, finish;
	int a = 0;
	
	/*calculating overhead for using loop*/
	clock_gettime(CLOCK_REALTIME, &start); // start time
	for(int i=0;i<LOOP_COUNT;i++){
		a++;
	}
	clock_gettime(CLOCK_REALTIME, &finish); // end time

	double diff = time_spent(start, finish) / MILLISECONDS; //converting time to milliseconds
	printf("\noverhead to run loop : %.2f ms\n", diff);
	
	/* calculating overhead for reading time*/
	a = 0;
	double total_time = 0; 
	for(int i=0;i<LOOP_COUNT;i++){
		clock_gettime(CLOCK_REALTIME, &start);
		clock_gettime(CLOCK_REALTIME, &finish);
		total_time = total_time + time_spent(start,finish);
	}

	total_time = total_time / 1000;
	printf("\noverhead of reading : %.2f us\n", total_time);

}


