/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Thread Creation Time
*/ 

#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

#define NANOSECONDS 1000000000

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


void *func(void *it){}

int main() {

	struct timespec start, finish;
	
	pthread_t tid;
	clock_gettime(CLOCK_REALTIME, &start);
	pthread_create(&tid, NULL, func, NULL);
	clock_gettime(CLOCK_REALTIME, &finish);
	
	printf("thread creation time : %.2f us \n", time_spent(start, finish)/1000);


}
