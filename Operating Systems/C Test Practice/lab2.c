#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 2)
	{
		printf("Incorrect number of arguments - expected 2");
		exit(1);
	}
	FILE *f = fopen(argv[1], "r");
	if(f == NULL){
		perror("Error on open file");
		exit(1);
	}
	char *s = malloc(sizeof(char) * 100);
	//fscanf(f, "%s", s);
	int k = 0;
	FILE *out = fopen("out", "w");	
	while((k = fread(s, 1, 100, f)) > 0){
		s[k] = 0;
		printf("%s\n", s);
		fprintf(out, "%s", s);
	}
	s[k] = 0;
	//fprintf(out, "I just read %s\n", s);
	free(s);
	fclose(out);
	fclose(f);

	return 0;
}
