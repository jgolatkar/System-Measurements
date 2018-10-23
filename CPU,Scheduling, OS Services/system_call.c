#include<stdio.h>
#include<unistd.h>
#include<time.h>

#define MILLISECONDS 1000000

double time_spent(struct timespec t1, struct timespec t2){
	return ((t2.tv_sec * 1000000000 + t2.tv_nsec) - (t1.tv_sec * 1000000000 + t1.tv_nsec));
}


int main() {
	struct timespec start,end;
	int i,j;
	long ITR = 1000000;
	double total_time = 0;	
	/* time average for system call getpid() 
	using clock_gettime() as gettimeofday() is obsolete as marked by POSIX */
	
	for(i = 0; i < ITR; i++){
		clock_gettime(CLOCK_REALTIME,&start);
		j = getpid(); 
		clock_gettime(CLOCK_REALTIME,&end);
		total_time = total_time + time_spent(start,end);
	}
	
	total_time = (total_time / 1000) / ITR ;
	printf("Average time spent per system call getpid(): %.2f ms\n",total_time)	;
	return 0; 

}
