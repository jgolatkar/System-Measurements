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
#define NANOSECONDS 1000000000

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

struct timespec start, finish;
double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


void *func(void *it){
	clock_gettime(CLOCK_REALTIME, &start);
	for(int i=0;i<100000;i++);
	clock_gettime(CLOCK_REALTIME, &finish);
	//pthread_exit(NULL);
}

int main() {

	
	
	pthread_t tid;
	
	int id = pthread_create(&tid, NULL, &func, NULL);
	
	pthread_join(tid, NULL);
	
	
	printf("thread creation time : %.2f us \n", (time_spent(start, finish)/1000));


}
