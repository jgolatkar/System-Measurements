/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: Memory	
	Task: RAM Read and Write Bandwidth
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"timestamp.h"
#define SIZE (8 * 1024 * 1024)
#define NANOSECONDS 1000000000 

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


int main(){
	unsigned long start, finish;
	unsigned long total_time = 0;
	int *buffer = (int *)malloc(SIZE * sizeof(int));
	int step = 2;
	int val = 0;
	int a = 0;
	int b = 0;
	/*writing into array with loop unrolling*/
	//clock_gettime(CLOCK_REALTIME, &start);
	start = rdtsc_begin();
	for(int i=0;i < SIZE;i=i+step){
		buffer[i] = 10;
		buffer[i + 1] = 10;
	}
	finish = rdtsc_end();
	//clock_gettime(CLOCK_REALTIME, &finish);
	total_time = finish - start;
	printf("memory write time : %ld cycles \n", total_time);
	
	/*reading from memory time*/
	total_time = 0;
	start = rdtsc_begin();
	//clock_gettime(CLOCK_REALTIME, &start);
	for(int i=0;i < SIZE;i=i+step){
		a += buffer[i] ;
		b += buffer[i + 1] ;
	}
	finish = rdtsc_end();
	total_time = finish - start;
	//clock_gettime(CLOCK_REALTIME, &finish);
	printf("memory read time : %ld cycles \n", total_time);
	free(buffer);
}
