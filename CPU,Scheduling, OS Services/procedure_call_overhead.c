/*
	Project: System Measurement
	Course: ITCS 6144 Operating System Design | Fall 2018
	Group: 1. Jitesh B Golatkar | 2. Sanchari Chatterjee
	Module: CPU, Scheduling & OS Services	
	Task: Procedure Call Overhead 
*/


#include<stdio.h>
#include<time.h>

#define LOOP_COUNT 1000000
#define NANOSECONDS 1000000000
#define MILLISECONDS 1000000


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
	
	struct timespec start, finish;
	double total_time = 0; 
	long ITR = 1000000;
	
		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);
				func_arg_zero();
			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}

		printf("\n avg time taken 0 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	

		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_one(1);
			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);
			
		}
		
		printf("\n avg time taken 1 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	

		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_two(1,2);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
		printf("\n avg time taken 2 arg: %.2f us\n", (total_time ) / ITR);
		total_time = 0;	

		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_three(1,2,3);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
		
		printf("\n avg time taken 3 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	

		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_four(1,2,3,4);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
	
		printf("\n avg time taken 4 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	
		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_five(1,2,3,4,5);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
		
		printf("\n avg time taken 5 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	
		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_six(1,2,3,4,5,6);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
		
		printf("\n avg time taken 6 arg: %.2f us\n", (total_time) / ITR);
		total_time = 0;	
		for(int i = 0; i < ITR; i++){
			clock_gettime(CLOCK_REALTIME, &start);

				func_arg_seven(1,2,3,4,5,6,7);

			clock_gettime(CLOCK_REALTIME, &finish);
			total_time = total_time + time_spent(start,finish);

		}
		

		printf("\n avg time taken 7 arg: %.2f us\n", (total_time) / ITR);

	

}
