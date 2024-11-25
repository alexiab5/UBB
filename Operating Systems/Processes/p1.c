#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	if(argc != 2)
		perror("You must provide a single number");
	int n = atoi(argv[1]);
	for(int i = 0; i < n; i++){
		int f = fork();
		if(f == -1){
			perror("Error on fork");
		}
		else if(f == 0){ // child process
			printf("Child %d -> PID %d, Parent -> PID %d\n", i, getpid(), getppid());
			exit(0);			
		}
		else{
			printf("Parent ID %d, Created Child %d\n", getpid(), f);
			// wait(0); => create hierarch: P=>C0=>C1=>...=>Cn
		}
	}
	for(int i = 0; i < n; i++)
		wait(0); // clean up pids and avoid zombie processes
			 // for every fork => wait!!!, only at the end, when the child is not interrupted
	return 0;
}
