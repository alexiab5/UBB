#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct {
	int id;
	char* word;
	int* freq;
}data;

pthread_mutex_t mtx;

void*f (void* arg){
	data d = *((data*)arg);
	printf("Thread %d received word: %s\n", d.id, d.word);
	int len = strlen(d.word);
	for(int i = 0; i < len; i++){
		if(d.word[i] >= 'a' && d.word[i] <= 'z'){
			pthread_mutex_lock(&mtx);
			d.freq[d.word[i] - 'a']++;
			pthread_mutex_unlock(&mtx);
		}
	}
	free(d.word);
	return NULL;	
}

int main(int argc, char** argv){
	if(argc < 2){
		perror("Please provide at least one argument");
		exit(1);
	}
	int nr = 'z' - 'a' + 1;
//	int* arr = (int*)malloc(('z'-'a'+1) * sizeof(char));
//	for(int i = 0; i < nr; i++)
//		arr[i] = 0;
	int arr[26];
	for(int i = 0; i < 26; i++)
		arr[i] = 0;
	pthread_t th[argc - 1];
	data* d = (data*)malloc((argc - 1) * sizeof(data));
	pthread_mutex_init(&mtx, NULL);
	for(int i = 0; i < argc - 1; i++){
		d[i].id = i + 1;
		d[i].word = malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
		strcpy(d[i].word, argv[i + 1]);
		d[i].word[strlen(argv[i + 1])] = '\0';
		d[i].freq = arr;
		if(0 != pthread_create(&th[i], NULL, f, &d[i])){
			perror("Error creating thread");
		}
	}
	for(int i = 0; i < argc - 1; i++){
		pthread_join(th[i], NULL);
	}
	pthread_mutex_destroy(&mtx);
	printf("Final frequency array: ");
	for(int i = 0; i < nr; i++)
		printf("%d ", arr[i]);
	printf("\n");
	//free(arr);
	free(d);
	return 0;
}
