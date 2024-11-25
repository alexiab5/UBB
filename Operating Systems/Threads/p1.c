#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t m;
int sum = 0;

void* f(void* a){
	while(1){
		int nr = rand() % 1001 - 500;
		pthread_mutex_lock(&m);
		if(abs(sum) > 5000){
			pthread_mutex_unlock(&m);
			break;
		}	
		sum += nr;
		printf("Thread %d generated: %d, sum = %d\n",*(int*)a, nr, sum);
		pthread_mutex_unlock(&m);
	}
	free(a);
	return NULL;
}

int main(int argc, char ** argv){
	if(argc != 2){
		perror("Please provide exactly once argument");
		exit(1);
	}
	int n = atoi(argv[1]);
	pthread_t th[n];
	int* j;
	srand(getpid());
	pthread_mutex_init(&m, NULL);
	sum = 0;
	for(int i = 0; i <n; i++){	
		j = (int*)malloc(sizeof(int));
		*j = i + 1;
		if(0 != pthread_create(&th[i], NULL, f, j)){
			perror("Error creating thread");
			free(j);
		}	
	}
	for(int i = 0; i < n; i++){
		if(0 != pthread_join(th[i], NULL)){
			perror("horror");
		}
	}
	pthread_mutex_destroy(&m);
	return 0;
}
