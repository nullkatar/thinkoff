#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Points {
	int x;
	int y;
};

int main(int argc, char const *argv[]) {

	int n, i, j, k, count = 0 ;

	scanf("%d", &n);

	struct Points* points = malloc(sizeof(struct Points) * n);

	for (i = 0; i < n; i++){
		scanf("%d %d", &(points[i].x), &(points[i].y));
	}

	int **matrix = malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++){
		matrix[i] = malloc(sizeof(int) * n);
	}

	for (i = 0; i < n; i++){
		for (j = 0; j <= i ; j++){
			matrix[j][i] = matrix[i][j] = pow((points[i].x -  points[j].x) , 2) + pow((points[i].y - points[j].y), 2);
		}
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			for (k = j + 1; k < n; k++){
				if (matrix[i][j] == matrix[i][k]){
					count++;
				}
			}
		}
	}

	printf("%d\n", count);
	
	return 0;
}



