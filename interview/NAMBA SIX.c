#include<stdio.h>
#include<stdlib.h>

int** d;

int p(int n, int k) {

	if (n < k) return p(n,n);

	if (k == 1){
		if ((n == 1) || (n == 0)){
			return 1; }
		else {
			return 0; }
	}

	if (d[n][k] >= 0){
		 return d[n][k]; }
	
	d[n][k] =  p(n, k - 1) + p(n - k, k - 1);
	
	return d[n][k];
}

int main() {

	int m, i, j;

	scanf("%d", &m);

	d = malloc(sizeof(int*) * (m+1));
	
	for (i = 0; i <= m; i++) {
		d[i] = malloc(sizeof(int) * (m+1));
		for (j = 0; j <= m; j++) {
			d[i][j] = -1;
		}
	}
	
	d[0][0] = 1;

	printf("%d\n", p(m, m));
	
	return 0;
}
