#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void f(int n){
	if(n > 0){
		int k = fork();
		if(k < 0){
			perror("Error on fork");
			exit(1);
		}
		if(k == 0){
			//printf("Child %d Parent %d\n", getpid(), getppid());
			f(n - 1);
		}
		else{
			printf("Parent %d Child %d\n", getpid(), k);
		}
	}
	wait(0);
	exit(0);	
}

int main(int argc, char* argv[]){
	if(argc != 2){
		perror("Provide exactly one argument");
		exit(1);
	}
	f(atoi(argv[1]));
	return 0;
}
