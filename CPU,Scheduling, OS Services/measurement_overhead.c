/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Measurement Overhead 
*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define LOOP_COUNT 10000
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
	char *buffer = (char*)malloc(sizeof(char));
	
	/*calculating overhead for using loop*/
	clock_gettime(CLOCK_REALTIME, &start); // start time
	for(int i=0;i<LOOP_COUNT;i++){
		
	}
	clock_gettime(CLOCK_REALTIME, &finish); // end time

	double diff = time_spent(start, finish) / 1000; //converting time to microseconds
	printf("\noverhead to run loop : %.2f us\n", diff);
	
	/* calculating overhead for reading time*/
	a = 0;

	clock_gettime(CLOCK_REALTIME, &start); // start time
	buffer[0] = 'a';
	clock_gettime(CLOCK_REALTIME, &finish); // end time
	diff = time_spent(start, finish) / 1000; //converting time to microseconds
	printf("\n overhead of reading : %.2f us\n", diff);

}


