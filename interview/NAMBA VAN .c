#include<stdio.h>
#include<stdlib.h>

int main() {

	int m, n, i, j;

	scanf("%d %d", &m, &n);

	int matrix[m*n];

	for (i = 0; i < m*n; i++){
		scanf("%d", &matrix[i]);
	}

	printf("%d %d\n", n, m);

	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			printf("%d", matrix[(m-j)*n+i-1]);
			if ((j % m) != 0)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
