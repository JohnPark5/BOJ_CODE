#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **A = NULL, **B = NULL;
	int N,M;
	
	scanf("%d %d",&N,&M);
	
	A = (int**)malloc(sizeof(int*)*N);
	B = (int**)malloc(sizeof(int*)*N);
	for(int i=0; i<N; i++) {
		A[i] = (int*)malloc(sizeof(int)*M);
		B[i] = (int*)malloc(sizeof(int)*M);
	}
	
	for(int k=0; k<2; k++)
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(k==0) {
				scanf("%d",&A[i][j]);
			}
			else {
				scanf("%d",&B[i][j]);
			}
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			printf("%d ",A[i][j] + B[i][j]);
		}
		printf("\n");
	}
	
	
	
	for(int i=0; i<N; i++) {
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
	
	return 0;
}
