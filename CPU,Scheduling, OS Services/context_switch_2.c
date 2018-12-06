/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Context Switch Time
*/ 

#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include"timestamp.h"

#define NANOSECONDS 1000000000
#define MESSAGE "Hello"
#define ITR 10000 

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

static int fd[2];
double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}



static void *func(void *a){
	unsigned long finish;
	//clock_gettime(CLOCK_MONOTONIC, &finish);
	finish = rdtsc_end();
	write(fd[1], &finish, sizeof(struct timespec));
	pthread_exit(NULL);
}


double processContextSwitch(int *fd){
	unsigned long start, finish;
	unsigned long total_time = 0;
	//int fd[2]; // fd[0] - Read End, fd[1] - Write End
	pid_t pid;

	/*child process creation*/
	
	
	if((pid = fork()) < 0){
		exit(1);
	}
	else if(pid > 0){
		//clock_gettime(CLOCK_MONOTONIC, &start);
		start = rdtsc_begin();
		wait(NULL);
		//close(fd[1]);
		read(fd[0],(void*)&finish, sizeof(struct timespec));
	}
	else{
		//clock_gettime(CLOCK_MONOTONIC, &finish);
		finish = rdtsc_end();		 
		/*child process writing*/
		//close(fd[0]); /*closing unused read end*/
		
		write(fd[1], &finish, sizeof(struct timespec));
		exit(0);
	}
	
	if(finish > start){
		total_time += finish - start;
	}
	return total_time;
	
}

int getProcessContextSwitch(){
	
	int fd[2];
	/*create new pipe*/
	if (pipe(fd) == -1){
		printf("pipe creation failed");
		return 1;
	}
	double res[ITR];
	double result = 0;
	double sum = 0;
	int i = 0;
	while(i < ITR){
		result = processContextSwitch(fd);
		if(result > 0){
			sum += result;
			i++;
		}
	}
	printf("process context switch time : %.2f cycles \n", sum / ITR );

}


int threadContextSwitch(){
	unsigned long start, finish;
	unsigned long total_time = 0;
	pthread_t tid;
	//int fd[2];
	pipe(fd);
	pthread_create(&tid, NULL, func, NULL);
	start = rdtsc_begin();
	//clock_gettime(CLOCK_MONOTONIC, &start);
	pthread_join(tid, NULL);
	//close(fd[1]);
	
	read(fd[0], &finish, sizeof(struct timespec));
	total_time = finish - start;
	return total_time;

}

void getThreadContextSwitch(){
	double result = 0;
	double sum = 0;
	int i = 0;
	while(i < ITR){
		result = threadContextSwitch();
		if(result > 0){
			sum += result;
			i++;
		}
	}

	printf("thread context switch time : %.2f cycles \n", sum/ITR);
}

int main(){
	
	
	getProcessContextSwitch();
	getThreadContextSwitch();
	
}
