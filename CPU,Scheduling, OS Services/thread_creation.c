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
#include<sys/wait.h>
#include"timestamp.h"
#define NANOSECONDS 1000000000
#define ITR 10000

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


void *func(void *lt){
	pthread_exit(NULL);
}

int main() {

	//struct timespec start, finish;
	//double total_time = 0;
	unsigned long start, finish;
	unsigned long total_time = 0;
	pthread_t tid;
	
	for(int i=0;i<ITR;i++){
		//clock_gettime(CLOCK_MONOTONIC, &start);
		start = rdtsc_begin();
		pthread_create(&tid, NULL, func, NULL);
		pthread_join(tid, NULL);
		//clock_gettime(CLOCK_MONOTONIC, &finish);
		finish = rdtsc_end();
		total_time += finish-start;
	}
	
	printf("thread creation time : %lu  \n", total_time/ITR);


}
