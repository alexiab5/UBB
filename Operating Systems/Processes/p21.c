#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
	if(arg != 2){
		perror("You must provide exactly one argument");
		exit(1);
	}
	pipe12[2], pipe21[2];
	int f = fork();
	if(f == -1)
		perror("Error on fork");
	else if (f == 0){ // child
		FILE* f;
		f = open(argv[1], "r");
		if(f == NULL){
			perror("Error on opening the file for reading");
		}
		else{
			int v[101];
			int n = fscanf(f, "%d", &v[0]);
			for(int i = 1; i <= n; i++)
				fscanf(f, "%d", &v[i]);
			for(int i = 1; i <= n; i++)
			fclose(f);
		}
	}
}
