#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#define NANOSECONDS 1000000000 
off_t FILESIZE;
int n;
double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}


//randomly read blocks
void readFileRandomly( int seq){
  void *buf = malloc(4096);
  char *files[] = {"size_8M_1","size_8M_2","size_8M_3","size_8M_4","size_8M_5","size_8M_6","size_8M_7","size_8M_8",};
  int fd = open(files[seq], O_RDONLY);


  off_t num = FILESIZE / 4096;
  off_t *access_list = (off_t*)malloc(num * sizeof(off_t));
  int i;
  for (i = 0; i < num; i++) 
  {
     access_list[i] = rand() % num;
  }


struct timespec start, finish;
	double total_time = 0;

  for (i = 0; i < num; i++) {

	if(posix_fadvise(fd, 0,0,POSIX_FADV_DONTNEED) < 0){
		printf("POSIX error");
		exit(1);
	}
	lseek(fd, access_list[i] * 4096, SEEK_SET);
	clock_gettime(CLOCK_REALTIME, &start);
    
    read(fd, buf, 4096);
	clock_gettime(CLOCK_REALTIME, &finish);
    total_time += time_spent(start, finish);
  }

  close(fd);
  printf(" %s , %.2lf\n",files[seq], total_time / ((double)num) /1000);

}

int main(int argc, char *argv[])
{
  /* code */
  FILESIZE = atoll(argv[1]);
  srand((unsigned int)time(NULL));

 
  int i;
  n = atoll(argv[2]);
 pid_t pids[n];
  printf("\n");
  for (i = 0; i < n; ++i) {
    if ((pids[i] = fork()) < 0) {
      perror("fork error");
      exit(1);
    } else if (pids[i] == 0) {
      readFileRandomly( i);
      exit(0);
    }else{
		wait(NULL);
	}
  }

  return 0;
}
