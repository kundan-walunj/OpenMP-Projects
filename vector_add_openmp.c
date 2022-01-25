#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define ARRAY_SIZE 4000000
#define NUM_THREDS 8
int main() {
 int n = ARRAY_SIZE;
 int *a = (int *) malloc(sizeof(int) * n), *b = (int *) 
malloc(sizeof(int) * n), *c = (int *) malloc(sizeof(int) * 
n);
 for(int i=0; i<n; i++) {
 a[i] = rand()*100;
 b[i] = rand()*100;
 }
 omp_set_num_threads(NUM_THREDS);
 double start, end;
 start = omp_get_wtime();
 for(int i=0; i<n; i++) {
 c[i] = a[i]+b[i];
 }
 end = omp_get_wtime();
 printf("\nTime taken for Serial: %lf\n", (end - start));
 start = omp_get_wtime();
 #pragma omp parallel for
 for(int i=0; i<n; i++) {
 c[i] = a[i]+b[i];
 }
 end = omp_get_wtime();
 printf("\nTime taken for Parallel: %lf\n", (end -
start));
 
}
