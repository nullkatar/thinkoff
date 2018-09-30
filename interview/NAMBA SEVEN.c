#include<stdio.h>
#include<math.h>

int main(){

	int n = 0;
	scanf("%d", &n);
	int a1[n];
	int a2[n];
	int new_per = 0;
	int max_per = 0;
	int i, j, k;	
	
	for( i = 0; i < n; i++){
		scanf("%d %d", &a1[i], &a2[i]);
	}
	for( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++) {
			for ( k = 0; k < n; k++) {
				new_per = sqrt( pow((a1[j] - a1[i]) , 2) + pow( (a2[j] - a2[i]) , 2)  ) + sqrt( pow((a1[k] - a1[i]), 2) +pow((a2[k] - a2[i]), 2  )) + sqrt(pow((a1[k] - a1[j]), 2) + pow((a2[k] - a2[j]), 2 ) ); 
				if (max_per < new_per){
					max_per = new_per;
					}
				}
			}
		}
	printf("%d", max_per);
return 0;
}
