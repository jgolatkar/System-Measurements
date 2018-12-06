/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Process Creation Time
*/ 

#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include"timestamp.h"
#define NANOSECONDS 1000000000
#define MILLISECONDS 1000000
#define ITR 10000

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}

int main() {

	//struct timespec start, finish;
	//double total_time = 0;
	unsigned long start, finish;
	unsigned long total_time = 0;
	int pid;
	for(int i=0;i < ITR; i++){
	//clock_gettime(CLOCK_MONOTONIC, &start);
	start = rdtsc_begin();	
	pid = fork();
	
	
	if (pid == 0){ 
		exit(1);
	}else{
		wait(NULL);
		finish = rdtsc_end();
		total_time += finish - start;
	}
	
	}
	printf("process creation time : %lu \n", total_time / ITR);
	


}
