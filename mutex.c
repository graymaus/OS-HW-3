#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

volatile int ncount;     //shared source
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //clear thread

void* do_loop(void*data)
{
	int i;
	for(i = 0; i<25000; i++)
	{
//		pthread_mutex_lock(&mutex); // create lock
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
		ncount ++;
		printf("loop1 : %d\n", ncount);
//		pthread_mutex_unlock(&mutex); // unlock
		sleep(0.0001);
	}
}
void* do_loop2(void*data)
{
	int i;
	for(i = 0; i<25000; i++)
	{
//		pthread_mutex_lock(&mutex); // create lock
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
		ncount ++;
		printf("loop2 : %d\n", ncount);
//		pthread_mutex_unlock(&mutex); // unlock
		sleep(0.0001);
	}
}

void* do_loop3(void*data)
{
	int i;
	for(i = 0; i<25000; i++)
	{
//		pthread_mutex_lock(&mutex); // create lock
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
		ncount ++;
		printf("loop3 : %d\n", ncount);
//		pthread_mutex_unlock(&mutex); // unlock
		sleep(0.0001);
	}
}

void* do_loop4(void*data)
{
	int i;
	for(i = 0; i<25000; i++)
	{
//		pthread_mutex_lock(&mutex); // create lock
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
		ncount ++;
		printf("loop4 : %d\n", ncount);
//		pthread_mutex_unlock(&mutex); // unlock
		sleep(0.0001);
	}
}
int main() 
{
	int	thr_id;
	pthread_t p_thread[4];
	int status;
	int a = 1;
	
	ncount =0;
	thr_id = pthread_create(&p_thread[0],NULL, do_loop, (void *)&a);
	sleep(0.0001);
	thr_id = pthread_create(&p_thread[1],NULL, do_loop2, (void *)&a);
	sleep(0.0001);
	thr_id = pthread_create(&p_thread[2],NULL, do_loop3, (void *)&a);
	sleep(0.0001);
	thr_id = pthread_create(&p_thread[3],NULL, do_loop4, (void *)&a);
	
	pthread_join(p_thread[0], (void *) &status);
	pthread_join(p_thread[1], (void *) &status);
	pthread_join(p_thread[2], (void *) &status);
	pthread_join(p_thread[3], (void *) &status);


	status = pthread_mutex_destroy(&mutex);
	printf("check : %d\n", status);
	return 0;

}
