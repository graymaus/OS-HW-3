#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#define MILLION 1000000
#define A_COL 2
#define A_ROW 2
#define B_ROW 2
#define B_COL 2

void* do_loop(void*data)
{
//		pthread_mutex_lock(&mutex); // create lock
    struct timeval tpstart, tpend;
    long timediff;
    int  i, j, k;
	static int a[A_ROW][A_COL];
	static int b[B_ROW][B_COL];
	static int c[A_ROW][B_COL];
	
	if (A_COL != B_ROW){
	printf("CANNOT CALCULATE\n");
	return 0;
	} 

    for(i=0;i<A_ROW;i++){
    for(j=0;j<A_COL;j++){
	printf("A(%d, %d)= ",i+1,j+1);
	scanf("%d",&a[i][j]);
    }
	}
    for(i=0;i<B_ROW;i++){
    for(j=0;j<B_COL;j++){
	printf("B(%d, %d)= ",i+1,j+1);
	scanf("%d",&b[i][j]);
    }
	}

    gettimeofday(&tpstart, NULL);
	for(i=0;i<A_ROW;i++){
	for(j=0;j<B_COL;j++){
	for(k=0;k<A_COL;k++){
	c[i][j] += a[i][k]*b[k][j];
	}
	}
	}
	printf("======RESULT======\n");
	for(i=0;i<A_ROW;i++){
	for(j=0;j<B_COL;j++){
	printf("%d ",c[i][j]);
	}
	printf("\n");
	}
	printf("\n");
    gettimeofday(&tpend, NULL);

    timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

    printf("It took %ld msec \n", timediff);
//		pthread_mutex_unlock(&mutex); // unlock
}


int main() 
{
	int	thr_id;
	pthread_t p_thread[2];
	int status;
	int a = 1;
	
	thr_id = pthread_create(&p_thread[0],NULL, do_loop, (void *)&a);
	
	pthread_join(p_thread[0], (void *) &status);

//	status = pthread_mutex_destroy(&mutex);
	printf("check : %d\n", status);
	return 0;

}
