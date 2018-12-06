#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TIMES 1
#define SIZE (8 * 1024 * 1024)
#define NANOSECONDS 1000000000 

double time_spent(struct timespec t1, struct timespec t2){
		return ((t2.tv_sec - t1.tv_sec)*NANOSECONDS + (t2.tv_nsec - t1.tv_nsec));
	}

int memSize[15] = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
int strides[5] = {4, 64, 128, 1024, 4096}; 

void fixedStride(int strideIndex,int ts);
int main(int argc, char * argv[]){

	//srand((unsigned int)time(0));
	fixedStride(4, TIMES);
	return 0;
}


double cacheAccessTime(int size, int stridlength){
	int *a = (int *)malloc(size * 1024 / 4 * sizeof(int));
	int num, length;
	length = stridlength / 4; //no of int fit in stride size
	num = size * 1024 / 4; //no of int fit in memory size
	int index;
	a[0] = 0;
	for(int i=0;i<num;i++){
		index = i+length;
		if(index>=num){
			index%=num;
		}
		a[i] = index;
	}

	int x=0;
	struct timespec start, finish;
	double totalTime = 0;
	int count = 10000;

	clock_gettime(CLOCK_REALTIME, &start);
	for(int i=0;i<count;i++){
		x = a[x];
	}
	clock_gettime(CLOCK_REALTIME, &finish);
	
	totalTime = (time_spent(start, finish) - 57)/ count - 2.27;
	//totalTime - memoryReadOverhead / STEP_COUNT - loop_overhead
	
	free(a);
	return totalTime;
}

void fixedStride(int strideIndex,int ts){
	for(int i=0; i<ts; i++){
		for(int j=0;j<15;j++){
			double averageTime = cacheAccessTime(memSize[j], strides[strideIndex]);
		printf("\n %d K %lf\n",memSize[j], averageTime);
		}
	}
}


