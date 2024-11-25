#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>          
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <error.h>
#include <errno.h>

int main(int argc, char* argv[]){
	if(argc < 2 || argc > 11){
		perror("You must provide between 1 and 10 arguments");
		exit(1);
	}
	int n = argc - 1;
	int p[n][2];
	// create the n pipes
	for(int i = 0; i < n; i++){
		if(-1 == pipe(p[i])){
			char msg[30];
			sprintf(msg, "Error on creating pipe %d", i+1);
			perror(msg);
			exit(1);
		}
	}
	for(int i = 0; i < n; i++){
		int f = fork();
		if(f == -1){
			char msg[30];
			sprintf(msg, "Error on fork %d", i+1);
			perror(msg);
			exit(1);
		}
		else if(f == 0){
			// close all unnecessary pipes
			for(int j = 0; j < n; j++){
				if(i != j){
					close(p[j][0]);
					close(p[j][1]);
				}
			}
			close(p[i][0]);
			int lcount = 0, dcount = 0;
			for(int j = 0; j < strlen(argv[i + 1]); j++){
				if(isalpha(argv[i+1][j]))
					lcount++;
				else if(isdigit(argv[i+1][j]))
					dcount++;
			}
			// send the two counts through pipe
			if(-1 == write(p[i][1], &lcount, sizeof(int))){
				close(p[i][1]);
				error(1, errno, "Error writing letter count from child %d\n", i+1);	
			}
			if(-1 == write(p[i][1], &dcount, sizeof(int))){
				close(p[i][1]);
				error(1, errno, "Error writing digit count from child %d\n", i+1);	
			}
			close(p[i][1]);
			exit(0);
		}
	}
	int totalLetters = 0, totalDigits = 0;
	for(int j = 0; j < n; j++){
		close(p[j][1]);
	}
	for(int i = 0; i < n; i++){
		int l, d;
		if(-1 == read(p[i][0], &l, sizeof(int))){
			error(1, errno, "Error reading letter count from child %d\n", i+1);
		}
		if(-1 == read(p[i][0], &d, sizeof(int))){
			error(1, errno, "Error reading digit count from child %d\n", i+1);
		}
		totalLetters += l;
		totalDigits += d;
		close(p[i][0]);
		printf("Child %d: %d letters %d digits\n", i+1, l, d);
	}
	for(int i = 0; i < n; i++)
		wait(0);
	printf("Total: %d letters %d digits", totalLetters, totalDigits);
	return 0;
}
