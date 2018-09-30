#include "stdio.h"
#include "stdlib.h"


int search(int v, int* colors, int** matrix, int n){
	int m;
	colors[v] = 1;

	for (m = 0; m < n; m++){

		if (matrix[v][m] && (colors[m] == 1)){
			return 1;
		}
	}

	for (m = 0; m < n; m++){

		if (matrix[v][m] && (colors[m] == 0)){
			if (search(m, colors, matrix, n) == 1){
				return 1;
			}
		}
	}

	colors[v] = 2;
	return 0;
}

int main() {

	int n, i, j;

	scanf("%d", &n);

	int **matrix = malloc(sizeof(int*) * n);
	int *colors = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++){
		matrix[i] = malloc(sizeof(int) * n);
		colors[i] = 0;
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i = 0; i < n; i++){
		if ((colors[i] == 0) && search(i, colors, matrix, n)){
			printf("1");
			return 0;
		}
	}

	printf("0");	

	return 0;
}
