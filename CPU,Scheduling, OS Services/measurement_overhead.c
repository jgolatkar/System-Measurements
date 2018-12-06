/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Measurement Overhead 
*/

#include"timestamp.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
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
	
	//struct timespec start, finish;
	unsigned long start, finish;
	unsigned long total_time_reading, total_time_loop;
	total_time_reading=0;
	total_time_loop=0;
	
	/*calculating overhead for using loop*/
	//clock_gettime(CLOCK_REALTIME, &start); // start time
	start = rdtsc_begin();
	for(int i=0;i<LOOP_COUNT;i++){
		
	}
	finish = rdtsc_end();
	//clock_gettime(CLOCK_REALTIME, &finish); // end time

	//total_time_loop = time_spent(start, finish);
	total_time_loop = finish - start;
	printf("\noverhead to run loop : %lu\n", total_time_loop / LOOP_COUNT);
	
	/* calculating overhead for reading time*/
	//rdtsc();
	for(int i=0;i<LOOP_COUNT;i++){
		//clock_gettime(CLOCK_REALTIME, &start); // start time
		//clock_gettime(CLOCK_REALTIME, &finish); // end time
		start = rdtsc_begin();
		//sleep(10);
		finish = rdtsc_end();
		total_time_reading = total_time_reading + (finish - start);
	}
	printf("\n overhead of reading : %lu\n", total_time_reading / LOOP_COUNT);

}


