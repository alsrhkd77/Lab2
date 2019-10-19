/*testmalloc.c*/
#include <stdio.h>
#include <stdlib.h>

/*행렬 출력 함수*/
void print_matrix(int **matrix, int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void){
	int row, col;
	int **matrix1;
	int **matrix2;
	int **matrix3;

	printf("행렬의 행(row) 크기를 입력하세요: ");
	scanf("%d",&row);
	printf("행렬의 열(col)) 크기를 입력하세요: ");
	scanf("%d",&col);

	/*행 메모리 할당*/
	matrix1 = (int *)malloc((row) *sizeof(int *));
	if(matrix1 == NULL){
		printf("matrix1의 행에 메모리를 할당하지 못했습니다.");
		exit(-1);
	}
	matrix2 = (int *)malloc((row) *sizeof(int *));
	if(matrix2 == NULL){
		printf("matrix2의 행에 메모리를 할당하지 못했습니다.");
		exit(-1);
	}
	matrix3 = (int *)malloc((row) *sizeof(int *));
	if(matrix3 == NULL){
		printf("결과 matrix3의 행에 메모리를 할당하지 못했습니다.");
		exit(-1);
	}

	/*행 메모리 할당*/
	for(int i=0; i<row; i++){

		matrix1[i] = (int *)malloc((col) *sizeof(int));
		if(matrix1[i] == NULL){
			printf("matrix1의 열에 메모리를 할당하지 못했습니다.");
			exit(-1);
		}

		matrix2[i] = (int *)malloc((col) *sizeof(int));
		if(matrix2[i] == NULL){
			printf("matrix2의 열에 메모리를 할당하지 못했습니다.");
			exit(-1);
		}

		matrix3[i] = (int *)malloc((col) *sizeof(int));
		if(matrix3[i] == NULL){
			printf("결과 matrix의 열에 메모리를 할당하지 못했습니다.");
			exit(-1);
		}

		for(int c=0; c<col; c++){
			matrix1[i][c] = (int)(rand()%100);
			matrix2[i][c] = (int)(rand()%100);
			matrix3[i][c] = matrix1[i][c] + matrix2[i][c];
		}
	}

	printf("첫 번째 입력 행렬\n");
	print_matrix(matrix1, row, col);
	printf("두 번째 입력 행렬\n");
	print_matrix(matrix2, row, col);
	printf("결과 행렬\n");
	print_matrix(matrix3, row, col);

	for(int k=0; k<row; k++){
		free((int *)matrix1[k]);
		free((int *)matrix2[k]);
		free((int *)matrix3[k]);
	}

	free((int *)matrix1);
	free((int *)matrix2);
	free((int *)matrix3);
	return 0;
}
