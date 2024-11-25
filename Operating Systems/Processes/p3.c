#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int p01[2], p02[2], p10[2], p20[2];
	if(pipe(p01) == -1){
		perror("Error creating pipe from parent to child 1");
		exit(1);
	}
        if(pipe(p10) == -1){
                perror("Error creating pipe from child 1 to parent");
                exit(1);
        }
        if(pipe(p02) == -1){
                perror("Error creating pipe from parent to child 2");
                exit(1);
        }
        if(pipe(p20) == -1){
                perror("Error creating pipe from child 2 to parent");
                exit(1);
        }
	int f1 = fork();
	if(f1 == -1){
		perror("Error on fork 1");
		exit(1);
	}
	if(f1 == 0){ // inside child 1
		srand(getpid());		
		close(p02[0]);
		close(p02[1]);
		close(p20[0]);
		close(p20[1]);
		close(p01[1]);
		close(p10[0]);
		int n = rand() % 1001;
		printf("Child 1 generated %d\n", n);
		if(-1 == write(p10[1], &n, sizeof(int))){
			perror("Error sending number from child 1.\n");
			close(p01[0]);
			close(p10[1]);
			exit(1);
		}
		if(-1 == read(p01[0], &n, sizeof(int))){
			perror("Error reading result in child 1.\n");
			close(p01[0]);
			close(p10[1]);
			exit(1);
		}
		if(n == 1)
			printf("Child 1 won!\n");
		else if (n == -1)
			printf("Child 1 lost!\n");
		else
			printf("Draw!\n");
		close(p01[0]);
		close(p10[1]);
		exit(0);
	}
	int f2 = fork();
	if(f2 == -1){
		perror("Error on fork 2");
		exit(1);
	}
	if(f2 == 0){ // inside child 2
		srand(getpid());		
		close(p01[0]);
		close(p01[1]);
		close(p10[0]);
		close(p10[1]);
		close(p02[1]);
		close(p20[0]);
		int n = rand() % 1001;
		printf("Child 2 generated %d\n", n);
		if(-1 == write(p20[1], &n, sizeof(int))){
			perror("Error sending number from child 2.\n");
			close(p02[0]);
			close(p20[1]);
			exit(1);
		}
		if(-1 == read(p02[0], &n, sizeof(int))){
			perror("Error reading result in child 2.\n");
			close(p02[0]);
			close(p20[1]);
			exit(1);
		}
		if(n == 1)
			printf("Child 2 won!\n");
		else if (n == -1)
			printf("Child 2 lost!\n");
		else
			printf("Draw!\n");
		close(p02[0]);
		close(p20[1]);
		exit(0);
	}
	// in the parent
	close(p20[1]);
	close(p10[1]);
	close(p01[0]);
	close(p02[0]);
	int nr1, nr2, res1=0, res2=0;
	if(-1 == read(p10[0], &nr1, sizeof(int))){		
		perror("Error reading from child 1\n");
		close(p20[0]);
		close(p10[0]);
		close(p01[1]);
		close(p02[1]);
		wait(0);
		wait(0);
		exit(1);
	}	
	if(-1 == read(p20[0], &nr2, sizeof(int))){		
		perror("Error reading from child 2\n");
		close(p20[0]);
		close(p10[0]);
		close(p01[1]);
		close(p02[1]);
		wait(0);
		wait(0);
		exit(1);
	}
	printf("Parent recieved numbers %d and %d from child 1 and child 2\n", nr1, nr2);
	close(p20[0]);
	close(p10[0]);
	if(nr1 > nr2){
		res1 = 1;
		res2 = -1;
	}
	else if(nr1 < nr2){
		res2 = 1;
		res1 = -1;
	}
	if(-1 == write(p01[1], &res1, sizeof(int))){		
		perror("Error sending result to child 1\n");
		close(p01[1]);
		close(p02[1]);
		wait(0);
		wait(0);
		exit(1);
	}
	if(-1 == write(p02[1], &res2, sizeof(int))){		
		close(p01[1]);
		close(p02[1]);
		wait(0);
		wait(0);
		exit(1);
	}
	wait(0);
	wait(0);
	close(p01[1]);
	close(p02[1]);
	return 0;
}
