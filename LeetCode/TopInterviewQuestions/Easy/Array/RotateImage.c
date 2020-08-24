inline void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void rotate(int** matrix, int matrixsize, int* matrixcolsize){
  int previous;
  unsigned int maxI = matrixsize / 2;
  unsigned int maxJ = matrixsize - 1;
  unsigned int i, j;

  for (i = 0; i < maxI; i++, maxJ -= 2) {
    for (j = 0; j < maxJ; j++) {
      previous = matrix[i][j + i];
      swap(&previous, &matrix[j + i][matrixsize - 1 - i]);
      swap(&previous, &matrix[matrixsize - 1 - i][matrixsize - 1 - j - i]);
      swap(&previous, &matrix[matrixsize - 1 - j - i][i]);
      swap(&previous, &matrix[i][j + i]);
    }
  }
}

