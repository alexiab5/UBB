#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t mtx;
pthread_cond_t c;
int x;
int guess = -1;

void* f(void* arg){//guesser
	while(1){	
		pthread_mutex_lock(&mtx);
		if(guess == x){
			pthread_mutex_unlock(&mtx);
			break;
		}
		int nr = rand() % 1001;
		guess = nr;
		printf("Thread %d guessed: %d\n", *(int*)arg, nr);
		if(guess == x)
			pthread_cond_signal(&c);
		pthread_mutex_unlock(&mtx);	
	}
	free(arg);
	return NULL;
}

void* g(void* arg){ // announcer
	pthread_mutex_lock(&mtx);
//	while(x != guess){
		pthread_cond_wait(&c,&mtx);
//	}
	printf("Number guessed!\n");
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc, char** argv){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	srand(getpid());
	x = rand() % 1001;
	printf("The generated number is: %d\n", x);
	pthread_mutex_init(&mtx, NULL);
	pthread_cond_init(&c, NULL);
	pthread_t* th = (pthread_t*)malloc((n + 1) * sizeof(pthread_t));
	int* id = malloc(sizeof(int));
	*id = 1;
	if(0 != pthread_create(&th[0], NULL, g, id)){
		perror("Error creating thread");
	}
	for(int i = 1; i <= n; i++){
		id = malloc(sizeof(int));
		*id = i + 1;
		if(0 != pthread_create(&th[i], NULL, f, id)){
			perror("Error creating thread");
		}
	
	}
	for(int i = 0; i <= n; i++){
		pthread_join(th[i], NULL);
	}
	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&c);
	free(th);
	return 0;
}
