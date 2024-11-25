#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t mtx;
pthread_barrier_t bar;
int* arr;

void *populate(void* arg){
	for(int i = 0; i < 10; i++){
		arr[i] = rand() % 100 + 1;
	}
	printf("Thread: %d generated:", *((int*)arg));
	for(int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
	printf("\n");
	pthread_barrier_wait(&bar);
	return NULL;
}

void *process(void* arg){
	pthread_barrier_wait(&bar);
	int sum = 0;
	for(int i = 0; i < 10; i++){
		pthread_mutex_lock(&mtx);
		if(arr[i] != 0){
			sum += arr[i];
			arr[i] = 0;
			pthread_mutex_unlock(&mtx);
			usleep(10 * 1000);
		}
		else
			pthread_mutex_unlock(&mtx);
	}
	printf("Thread: %d ", *((int*)arg));
	printf("Total sum: %d\n",sum);
	return NULL;	
}

int main(int argc, char** argv){
	if(argc != 2){
		perror("Please provide exactly one argument");
		exit(1);
	}
	srand(getpid());
	int n = atoi(argv[1]);
	pthread_mutex_init(&mtx, NULL);
	pthread_barrier_init(&bar, NULL, 3);
	arr = malloc(10 * sizeof(int));
	int id[3];
	pthread_t th[3];
	id[0] = 1; id[1] = 2; id[2] = 3;
	for(int i = 0; i < n; i++){
		if(0 != pthread_create(&th[0], NULL, populate, &id[0])){
			perror("Error creating thread 1");
			free(arr);
			exit(1);
		}
		if(0 != pthread_create(&th[1], NULL, process, &id[1])){
			perror("Error creating thread 2");
		}	
		if(0 != pthread_create(&th[2], NULL, process, &id[2])){
			perror("Error creating thread 2");
		}
		for(int j = 0; j < 3; j++){
			pthread_join(th[j], NULL);
		}
		usleep(10 * 1000);
	}
	pthread_mutex_destroy(&mtx);
	pthread_barrier_destroy(&bar);
	free(arr);
	return 0;
}
