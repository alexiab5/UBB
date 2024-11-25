#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>          
#include <sys/stat.h>

void createFifo(char* name){
	if(-1 == mkfifo(name, 0600)){
		char msg[60];
		sprintf(msg, "Error on creating fifo %s", name);
		perror(msg);
		exit(1);
	}
}

void removeFifo(char* name){
	if(-1 == unlink(name)){
		char msg[60];
		sprintf(msg, "Error on removing fifo %s", name);
		perror(msg);
		exit(1);
	}
}

// process a
int main(int argc, char* argv[]){
	createFifo("./a2b");
	return 0;
}

