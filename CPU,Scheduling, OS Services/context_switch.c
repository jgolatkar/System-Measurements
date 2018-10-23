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

#define NANOSECONDS 1000000000
#define MESSAGE "Hello"

int a = 0;

/*
	function to find time difference 
	Returns: time(ns) in double 
*/

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}



void *func(void *it){
	//for(int i=0;i<1000000;i++);
}


int processContextSwitch(){
	struct timespec start, finish;
	int fd[2]; // fd[0] - Read End, fd[1] - Write End
	pid_t pid;
	struct timespec readbuff;

	/*create new pipe*/
	if (pipe(fd) == -1){
		printf("pipe creation failed");
		return 1;
	}
	
	/*child process creation*/
	
	pid = fork();
	if(pid < 0){
		printf("fork failed");	
	}
	
	if (pid == 0){ /*child process writing*/
		close(fd[0]); /*closing unused read end*/
		clock_gettime(CLOCK_REALTIME, &finish);
		//for(int i=0;i<1000000;i++);
		write(fd[1], &finish, sizeof(finish));
		close(fd[1]);
		return 0;
	}
	/* parent process reading */
	close(fd[1]);
	clock_gettime(CLOCK_REALTIME, &start);
	read(fd[0], &readbuff, sizeof(readbuff));
	close(fd[0]);
	printf("process context switch time : %.2f us \n", time_spent(start, readbuff)/1000);
	
}


int threadContextSwitch(){
	struct timespec start, finish;
	pthread_t tid;
	struct timespec readbuff;

	clock_gettime(CLOCK_REALTIME, &start);
	pthread_create(&tid, NULL, func, NULL);
	

	pthread_join(tid, NULL);
	clock_gettime(CLOCK_REALTIME, &finish);

	printf("thread context switch time : %.2f us \n", time_spent(start, finish)/1000);
	return 0;

}

int main(){

	threadContextSwitch();
	processContextSwitch();
	
}
