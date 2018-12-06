#include<stdio.h>
#include<stdint.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>

#define NANOSECONDS 1000000000 

const off_t READBLOCKSIZE = 4*1024; // because physical sector size is 4K


double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


int main(int argc, const char *argv[]){
struct timespec start, finish;
double totalTime = 0;
void* buffer = malloc(READBLOCKSIZE);
const off_t FILESIZE = atoll(argv[1]);
int file = open(argv[2], O_RDONLY | O_SYNC);


//seek last block in the file
lseek(file, FILESIZE - 1, SEEK_SET);
off_t totalBytes = 0;

//read file from end to start to avoid prefetching and put into memory 
while(1){
	lseek(file, -2*READBLOCKSIZE, SEEK_CUR);
	ssize_t bytes = read(file, buffer, READBLOCKSIZE);
	if(bytes <= 0 || totalBytes >= FILESIZE)
		break;
	totalBytes += bytes;
}

close(file); // closing file

//reading file again from file cache

file = open(argv[2], O_RDONLY | O_SYNC);
totalBytes = 0;

lseek(file, FILESIZE-1, SEEK_SET);
/*uint64_t start;
uint64_t end;
uint64_t total_time = 0;*/

//read backward
while(1){
	lseek(file, -2*READBLOCKSIZE, SEEK_CUR);
	clock_gettime(CLOCK_REALTIME, &start);
	ssize_t bytes = read(file, buffer, READBLOCKSIZE);
	clock_gettime(CLOCK_REALTIME, &finish);
	//total_time = finish - start;
	if(bytes <= 0 || totalBytes >= FILESIZE)
		break;
	totalBytes += bytes;
	totalTime = totalTime + time_spent(start, finish);
}

close(file);
free(buffer);
printf("total time : %.2f us \n", (totalTime/(FILESIZE / READBLOCKSIZE))/1000);


return 0;
}

