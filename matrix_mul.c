#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
void get_matrix(int a[10][10], int m, int n){
 int i,j;
 i=j=0;
 for(i=0; i<m; i++){
	for(j=0; j<n; j++){
		scanf("%d", &a[i][j]);	
	}
 }
}

void matrix_mul_par(int a[10][10], int b[10][10], int res[10][10], int m1, int n2, int m2){
	int i,j,k;
	printf("\nMultiplication of given two matrices is by parallel:\n\n");
	clock_t var=clock();
	#pragma omp parallel for
	for(i=0; i<m1; i++){
		for(j=0; j<n2; j++){
			res[i][j] = 0;
			for(k=0; k<m2; k++){
				res[i][j] += a[i][k] * b[k][j];		
			}
			printf("%d\t", res[i][j]);
		}
		printf("\n");	
	}
	clock_t end=clock();
	double parallel = (double)(end-var);
	printf("Time taken by parallel execution is : %lf\n", parallel);
	
}

void matrix_mul_seq(int a[10][10], int b[10][10], int res[10][10], int m1, int n2, int m2){
	int i,j,k;
	printf("\nMultiplication of given two matrices is by sequential:\n\n");
	clock_t var=clock();
	for(i=0; i<m1; i++){
		for(j=0; j<n2; j++){
			res[i][j] = 0;
			for(k=0; k<m2; k++){
				res[i][j] += a[i][k] * b[k][j];		
			}
			printf("%d\t", res[i][j]);
		}
		printf("\n");	
	}
	clock_t end=clock();
	double seq = (double)(end-var);
	printf("Time taken by sequential execution is : %lf\n", seq);
	
}

 int main()
{
	int m1, n1, m2, n2, a[10][10], b[10][10], ans[10][10];

	printf("Enter the number of rows and columns of Matrix1:\n");
	scanf("%d%d", &m1,&n1);
	printf("Enter the elements of first matrix \n");
	get_matrix(a,m1,n1);
	
	printf("Enter the number of rows and columns of Matrix2:\n");
	scanf("%d%d", &m2,&n2);
	printf("Enter the elements of Matrix 2 \n");
	get_matrix(b,m2,n2);
	
	
	if(n1!=m2){
		printf("The number of columns in Matrix-1  must be equal to the number of rows in "
                "Matrix-2\n");	
	}
	matrix_mul_seq(a,b,ans,m1,m2,n2);
	matrix_mul_par(a,b,ans,m1,m2,n2);
	//display(ans,m2,n1);
	return 0;
}

