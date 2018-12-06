/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Procedure Call Overhead 
*/


#include<stdio.h>
#include<time.h>
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

int func_arg_zero(){};
int func_arg_one(int a){ return 0;};
int func_arg_two(int a, int b){ return 0;};
int func_arg_three(int a, int b, int c){return 0;};
int func_arg_four(int a, int b, int c, int d){ return 0;};
int func_arg_five(int a, int b ,int c, int d, int e){ return 0;};
int func_arg_six(int a, int b ,int c, int d, int e, int f){ return 0;};
int func_arg_seven(int a, int b ,int c, int d, int e, int f, int g){ return 0;};


int main(){
	
	//struct timespec start, finish;
	unsigned long start, finish;
	unsigned long total_time = 0;
	//double total_time = 0; 
	start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			
			func_arg_zero();
			

		}
	finish = rdtsc_end();
	total_time = finish - start;
		printf("\n avg time taken 0 arg: %lu \n", (total_time) / ITR);
		total_time = 0;	
	start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			func_arg_one(1);
			
		}
	finish = rdtsc_end();
	total_time = finish - start;
		printf("\n avg time taken 1 arg: %lu \n", (total_time) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			
			
				func_arg_two(1,2);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;
		printf("\n avg time taken 2 arg: %lu \n", (total_time ) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			//clock_gettime(CLOCK_MONOTONIC, &start);
			
				func_arg_three(1,2,3);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;
		printf("\n avg time taken 3 arg: %lu \n", (total_time) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			//clock_gettime(CLOCK_MONOTONIC, &start);
			
				func_arg_four(1,2,3,4);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;
		printf("\n avg time taken 4 arg: %lu \n", (total_time) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			//clock_gettime(CLOCK_MONOTONIC, &start);
			
				func_arg_five(1,2,3,4,5);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;
		printf("\n avg time taken 5 arg: %.lu \n", (total_time) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			//clock_gettime(CLOCK_MONOTONIC, &start);
			
				func_arg_six(1,2,3,4,5,6);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;
		printf("\n avg time taken 6 arg: %lu \n", (total_time) / ITR);
		total_time = 0;	
		start = rdtsc_begin();
		for(int i = 0; i < ITR; i++){
			//clock_gettime(CLOCK_MONOTONIC, &start);
			
				func_arg_seven(1,2,3,4,5,6,7);
			
			//clock_gettime(CLOCK_MONOTONIC, &finish);
			

		}
		finish = rdtsc_end();
		total_time = finish - start;

		printf("\n avg time taken 7 arg: %lu \n", (total_time) / ITR);

	

}
