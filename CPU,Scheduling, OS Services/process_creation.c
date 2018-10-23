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

#define NANOSECONDS 1000000000
#define MILLISECONDS 1000000

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}

int main() {

	struct timespec start, finish;
	
	pid_t pid;
	clock_gettime(CLOCK_REALTIME, &start);
	pid = fork();
	clock_gettime(CLOCK_REALTIME, &finish);
	if(pid < 0){
		printf("fork failed");
		return 1;	
	}
	
	if (pid == 0){ 
		return 0;
	}
	printf("process creation time : %.2f us \n", time_spent(start, finish)/1000);


}
