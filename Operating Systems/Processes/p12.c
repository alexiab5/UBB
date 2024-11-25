#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		perror("Please provide exactly one argument!");
		exit(1);
	}
	int p10[2];
	if(-1 == pipe(p10)){
		perror("Error creating pipe from parent to child");
		exit(1);
	}
	int f = fork();
	if(f == -1){
		perror("Error on fork");
		exit(1);
	}
	else if(f == 0) { // inside child process
		// open file + read numbers
		close(p10[0]);
		FILE* file = fopen(argv[1], "r");
		if(file == NULL){
			perror("Error opening file");
			exit(1);
		}
		int n;
		if(1 != fscanf(file, "%d", &n)){
			perror("Error reading n from file.");
			close(p10[1]);
			fclose(file);
			exit(1);
		}
		//printf("%d\n", n);
		int* arr = malloc(n * sizeof(int));
		for(int i = 0; i < n; i++){
			if(1 != fscanf(file, "%d", &arr[i])){
				perror("Error reading number %d from file.");
				free(arr);
				close(p10[1]);
				fclose(file);
				exit(1);
			}
			//printf("%d ", arr[i]);
		}
		fclose(file);
		if(-1 == write(p10[1], &n, sizeof(int))){
			free(arr);
			perror("Error writing n to pipe");
			close(p10[1]);
			exit(1);
		}
		if(-1 == write(p10[1], arr, n * sizeof(int))){
			perror("Error writing array to pipe");
			free(arr);
			close(p10[1]);
			exit(1);
		}
		free(arr);
		close(p10[1]);
		exit(0);
	}
	// inside parent process
	int status, exitCode;
	wait(&status);
	close(p10[1]);
	if(WIFEXITED(status) && 0 == (exitCode = WEXITSTATUS(status))){ // if the child terminated normally
		int n;
		if(-1 == read(p10[0], &n, sizeof(int))){
			perror("Error reading n from pipe");
			close(p10[0]);
			exit(1);
		}
		while(n > 0){
			printf("How many numbers do you want? %d available -> ", n);
			int nr;
			scanf("%d", &nr);
			if(nr <= 0){
				break;
			}
			if(nr > n)
				nr = n;
			n -= nr;
			for(int i = 0; i < nr; i++){
				int number;
				if(-1 == read(p10[0], &number, sizeof(int))){
					perror("Error reading number from pipe");
					close(p10[0]);
					exit(1);
				}
				printf("%d ", number);
			}
			printf("\n");
		}
	}
	else{
		printf("Child process terminated with exit code %d. Terminating!\n", exitCode);
	}
	close(p10[0]);	
	return 0;
}
