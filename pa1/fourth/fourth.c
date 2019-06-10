#include <stdio.h>
#include <stdlib.h>

void multiply(int **matOne, int **matTwo, int rows1, int rows2, int cols1, int cols2) {
  int **result;
  int i;
  int j;
  int k;
  result = (int**)malloc(rows1*sizeof(int*));
  for(i = 0; i < rows1; i++){
    result[i] = (int*)malloc(cols2*sizeof(int));
  }
  /*for(j = 0; j < cols2; j++){
    result[j] = (int*)malloc(cols2*sizeof(int));
  }
  */
  /*(for (i = 0; i < rows1; i++) {
		for (j = 0; j < cols2; j++) {
			result[i][j] = 0;
			for (k = 0; k < cols1; k++) {
				*(*(result + i) + j) += *(*(matOne + i) + k) * *(*(matTwo + k) + j);
			}
		}
	}
*/

  for(i = 0; i < rows1; i++){
    for(j = 0; j < cols2; j++){
      result[i][j] = 0;
      for(k = 0; k < rows2; k++){
	       result[i][j] += matOne[i][k]*matTwo[k][j];
      }
    }
  }
  /*int total = 0;
  for(i = 0; i < rows1; i++) {
    for(j = 0; j < cols2; j++) {
      for(k = 0; k < rows2; k++) {
          total += matOne[i][k]*matTwo[k][j];
        }
      result[i][j] = total;
      total = 0;
    }
  }
*/
  int m = 0;
  int n = 0;
  for(m = 0; m < rows1; ++m) {
    for(n = 0; n < cols2; ++n) {
      printf("%d\t", result[m][n]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int rows;
  int cols;
  int rows2;
  int cols2;
  int **matrix1;
  int **matrix2;

  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");
  fscanf(fptr, "%d\t %d\n", &rows, &cols);

  matrix1 = (int**)malloc(rows*sizeof(int*)); //initializes matrix

  int i;
  int j;
  for(i = 0; i < rows; i++) { //initializes each row of the matrix1;
    matrix1[i] = (int*)malloc(cols*sizeof(int));
  }
  int counter = 0;
  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      matrix1[i][j] = ++counter;
    }
  }
  //printf("%d %d\n",rows, cols );
  int numToAdd;
  for(i = 0; i < rows; ++i){ // reads values into matrix1
    for(j = 0; j < cols; ++j){
      fscanf(fptr, "%d", &numToAdd);
      matrix1[i][j] = numToAdd;
    }
  }
  //printf("%d %d\n",rows, cols );

  fscanf(fptr, "%d\t %d\n", &rows2, &cols2); //gets rows and cols of 2nd matrix
  //printf("%d %d\n",rows2, cols2 );
  matrix2 = (int**)malloc(rows2*sizeof(int*));

  for(i = 0; i < rows2; i++) { //initializes each row of matrix2;
    matrix2[i] = (int*)malloc(cols2*sizeof(int));
  }
  //printf("%d %d\n",rows2, cols2 );
  counter = 0;
  for(i = 0; i < rows2; i++) {
    for(j = 0; j < cols2; j++) {
      matrix2[i][j] = ++counter;
    }
  }
  //printf("%d %d\t",rows2, cols2 );

  int numToAdd2;
  for(i = 0; i < rows2; ++i){ // reads values into matrix1
    for(j = 0; j < cols2; ++j){
      fscanf(fptr, "%d", &numToAdd2);
      matrix2[i][j] = numToAdd2;
    }
  }
  //free(fptr);
  if (cols != rows2) {
    printf("bad-matrices\n");
  }
  else {
    multiply(matrix1, matrix2, rows, rows2, cols, cols2);
  }
  free(matrix1);
  free(matrix2);
  return 0;
}
