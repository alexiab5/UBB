#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

typedef struct{
	pthread_mutex_t *mtx;
	int* letters;
	int* special;
	int* digits;
	char* word;
}data;

void* f(void* arg){
	data d = *(data*)arg;
	int len = strlen(d.word);
	int l = 0, s = 0, dig = 0;
	printf("Thread\n");
	for(int i = 0; i < len; i++){
		if(isdigit(d.word[i]))
			dig++;
		else if(isalpha(d.word[i]))
			l++;
		else s++;
	}	
	if(l > 0){
		pthread_mutex_lock(&d.mtx[0]);
		*(d.letters) += l;
		pthread_mutex_unlock(&d.mtx[0]);
	}	
	if(dig > 0){
		pthread_mutex_lock(&d.mtx[1]);
		*(d.digits) += dig;
		pthread_mutex_unlock(&d.mtx[1]);
	}	
	if(s > 0){
		pthread_mutex_lock(&d.mtx[2]);
		*(d.special) += s;
		pthread_mutex_unlock(&d.mtx[2]);
	}
	return NULL;
}

int main(int argc, char** argv){
	pthread_t th[argc - 1];
	pthread_mutex_t m[3];
	for(int i = 0; i < 3; i++)
		pthread_mutex_init(&m[i], NULL);
	data d[argc - 1];
       	int letters = 0, special = 0, digits = 0;	
	for(int i = 0; i < argc - 1; i++){
		d[i].letters = &letters;
		d[i].special = &special;
		d[i].digits = &digits;
		d[i].mtx = m;
		d[i].word = argv[i + 1];
		if(0 != pthread_create(&th[i], NULL, f, &d[i])){
			perror("Error creating mutex");
		}
	}
	for(int i = 0; i < argc - 1; i++)
		pthread_join(th[i], NULL);
	for(int i = 0; i < 3; i++)
		pthread_mutex_destroy(&m[i]);
	printf("Total number of digits: %d letters: %d: special characters:%d\n", digits, letters, special);
	return 0;
}
