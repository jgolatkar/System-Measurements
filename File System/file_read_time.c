
#define _GNU_SOURCE
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdint.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"timestamp.h"
#define NANOSECONDS 1000000000 

const off_t FILEBLOCK = 4*1024;
off_t FILESIZE;

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


int main(int argc, const char *argv[]){
	/*struct timespec start, finish;
	double totalTime = 0;*/

	unsigned long start, finish;
	unsigned long total_time = 0;
	FILESIZE = atoll(argv[1]);
	srand((unsigned int)time(NULL));
	void* buffer = malloc(FILEBLOCK );
	
	int fd = open(argv[2], O_RDONLY | O_SYNC);

	if(posix_fadvise(fd, 0,0,POSIX_FADV_DONTNEED) < 0){
		printf("POSIX error");
		exit(1);
	}

	//read file sequentially
	while(1){

		//clock_gettime(CLOCK_REALTIME, &start);
		//using time stamp counter to read cycles
		start = rdtsc_begin();
		ssize_t bytes = read(fd, buffer, FILEBLOCK);
		if(bytes <= 0){
			break;		
		}
		//printf("reading finished");
		finish = rdtsc_end();
		//clock_gettime(CLOCK_REALTIME, &finish);
		total_time = total_time + finish - start;
	}
	close(fd);
	
	double blocks = FILESIZE / FILEBLOCK;
	
	printf("sequential file read time: %.2f us\n", (total_time / blocks)/2.5/1000);

	// read file randomly

	fd = open(argv[2], O_SYNC);
	
	for(int i=0;i<blocks;i++){
		off_t k = rand() % (int)blocks;
		//clock_gettime(CLOCK_REALTIME, &start);
		start = rdtsc_begin();
		lseek(fd, k * FILEBLOCK, SEEK_SET);
		ssize_t bytes = read(fd, buffer, FILEBLOCK);
		finish = rdtsc_end();		
		//clock_gettime(CLOCK_REALTIME, &finish);
		total_time = total_time + (finish - start);	
	}
	close(fd);
	free(buffer);
	printf("random file read time: %.2f us\n", (total_time / blocks)/2.5/1000);
}
