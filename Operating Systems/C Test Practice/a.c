#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
int n, m, i, j;
char c;
FILE* f = fopen(argv[1], "r");
if(f == NULL){
	perror("Could not open file");
	return 1;
}	
if(fscanf(f, "%d %d", &n, &m) <= 0)
{
	perror("Could not read row, cols from file");
	return 1;
}
 
char** matrix = (char**) malloc(n * sizeof(char*));
if(matrix == NULL){
	perror("Error allocating memory");
	return 1;
}
	
for(i = 0; i < n; i++) {
    matrix[i] = (char *) malloc(m * sizeof(char));
    if(matrix[i] == NULL){
	for(j = 0; j <= i; j++)
		free(matrix[j]);
	free(matrix);
	perror("Error allocating memory");
	return 1;
    }
    for(j = 0; j < m; j++) {
        fscanf(f, "%c", &c);
        while(c == ' ' || c == '\n')
            fscanf(f, "%c", &c);
        matrix[i][j] = c;
    }
}
 
for(i = 0; i < n; i++) {
    for(j = 0; j < m; j++) {
        if (matrix[i][j] == 'a' || matrix[i][j] == 'e' || matrix[i][j] == 'i' || matrix[i][j] == 'o' || matrix[i][j] == 'u'){
            printf("%c ", matrix[i][j]);
    }
 }
}
    printf("\n");
fclose(f); 
for(i = 0; i < n; i++) {
    free(matrix[i]);
}
 
free(matrix);
 
return 0;
}
