#include <string.h>
#include <stdlib.h>

void strclr(char *);

char * countAndSay(int n){
  char *result;
  char *temp;
  char *current;
  unsigned int sameNumbersCount;
  unsigned int insertIndex;
  unsigned int i;

  result = (char *) calloc(4463, sizeof(char));
  temp = (char *) calloc(4463, sizeof(char));

  result[0] = '1'; // default
  for (i = 1; i < n; i++) {
    strcpy(temp, result);
    strclr(result);

    current = temp;
    insertIndex = 0;
    while (*current != '\0') {
      sameNumbersCount = 1;
      while (*current != '\0' && *current == *(current + 1)) {
        sameNumbersCount++;
        current++;
      }

      result[insertIndex++] = sameNumbersCount + '0';
      result[insertIndex++] = *current;

      current++;
    }
  }

  return result;
}

void strclr(char *str) {
  char *c = str;

  while (*c != '\0') {
    *c = '\0';

    c++;
  }
}
