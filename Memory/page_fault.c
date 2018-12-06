#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/mman.h>
#include<fcntl.h>
#include"timestamp.h"

/* clear cache every time before running program
	sudo echo 3 | sudo tee /proc/sys/vm/drop_caches
*/

#define NANOSECONDS 1000000000 

unsigned int FILESIZE = 524288000; //500MB
unsigned int OFFSET = 8388608;//8MB
double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}

int main() {
	

	unsigned long start, finish;
	unsigned long total_time = 0;
	int count = 100;

	int fd = open("test", O_RDWR);
	char *map = (char *)mmap(NULL, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	char c;
	
	for(int i=0;i < count;i++){
		//clock_gettime(CLOCK_MONOTONIC, &start);
		start = rdtsc_begin();
		c = map[(((i+1)*OFFSET)%(FILESIZE - 1))]; //reading character from mapped file
		//clock_gettime(CLOCK_MONOTONIC, &finish);
		finish = rdtsc_end();
		total_time += finish - start;
	}

	printf("page fault average time: %ld\n", (total_time - 67)/ count - 6); //subtracting rdtsc overhead and loop overhead
	munmap(map, FILESIZE);
	close(fd);
	return 0;
	
}
