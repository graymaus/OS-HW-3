#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#define MILLION 1000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //clear thread

void* do_loop(void*data)
{
    struct timeval tpstart, tpend;
    long timediff;
    int  i, j, k;
	static int a[2][2];
	static int b[2][2];
	static int c[2][2];
	
	
    for(i=0;i<2;i++){
    for(j=0;j<2;j++){
    c[i][j] = 0;
	}
	}
	
    for(i=0;i<2;i++){
    for(j=0;j<2;j++){
    a[i][j] = i+j+1;
    }
	}
    for(i=0;i<2;i++){
    for(j=0;j<2;j++){
    b[i][j] = i+j+1;
    }
	}
	printf("======A======\n");
	for(i=0;i<2;i++){
	for(j=0;j<2;j++){
	printf("%d ",a[i][j]);
	}
	printf("\n");
	}
	printf("\n");
	printf("======B=====\n");
	for(i=0;i<2;i++){
	for(j=0;j<2;j++){
	printf("%d ",b[i][j]);
	}
	printf("\n");
	}
	printf("\n");

    gettimeofday(&tpstart, NULL);
	for(i=0;i<2;i++){
	for(j=0;j<2;j++){
	for(k=0;k<2;k++){
	c[i][j] += a[i][k]*b[k][j];
	}
	}
	}
	printf("======A*B======\n");
	for(i=0;i<2;i++){
	for(j=0;j<2;j++){
	printf("%d ",c[i][j]);
	}
	printf("\n");
	}
	printf("\n");
    gettimeofday(&tpend, NULL);

    timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

    printf("It took %ld msec \n", timediff);
}


int main() 
{
	int	thr_id;
	pthread_t p_thread[1];
	int status;
	int a = 1;
	
	thr_id = pthread_create(&p_thread[0],NULL, do_loop, (void *)&a);
	
	pthread_join(p_thread[0], (void *) &status);

	printf("check : %d\n", status);
	return 0;

}
