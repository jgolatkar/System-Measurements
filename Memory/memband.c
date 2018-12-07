#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
  	unsigned long start, end;
	unsigned long size, r, i;
	unsigned long total_time = 0;
    	unsigned char *buffer;

    size = 1000 * 1000 * 1000; //GB
    r = 100;

    buffer = calloc(n, 1);

    start = clock();

    for(i = 0; i < r; ++i) {
        memset(buffer, (int)i, n);
       	printf("measuring bandwidth\r");
        fflush(stdout);
    }

    end = clock();

    total_time = (end - start) / (double)CLOCKS_PER_SEC ;
    printf("Memory Bandwidth = %f GB/s\n", (double)n * r / total_time / 1e9);

    free(buffer);
}

