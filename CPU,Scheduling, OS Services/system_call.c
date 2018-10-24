#include<stdio.h>
#include<unistd.h>
#include<time.h>

#define NANOSECONDS 1000000000

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


int main() {
	struct timespec start,end;
	int i,j;
	long ITR = 100000;
	double total_time = 0;	
	time_t t;

	for(int i=0;i<ITR;i++){
		clock_gettime(CLOCK_REALTIME,&start); 
		getppid();
		clock_gettime(CLOCK_REALTIME,&end);
		total_time += time_spent(start,end);
	
	}
	total_time = (total_time / ITR) / 1000;
	printf("Average time spent per system call getppid(): %f us\n",total_time);
	return 0; 

}
