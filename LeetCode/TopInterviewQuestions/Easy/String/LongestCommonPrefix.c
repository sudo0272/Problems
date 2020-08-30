#include <stdlib.h>
#include <string.h>

unsigned int max(unsigned int *arr, int size) {
  unsigned int i;
  unsigned int maxValue = arr[0];

  for (i = 1; i < size; i++) {
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }

  return maxValue;
}

char * longestCommonPrefix(char **strs, int strsSize){
  unsigned int *strLengths;
  char *commonPrefix;
  unsigned int commonPrefixMaxLength;
  unsigned int i;
  unsigned int j;

  if (strsSize == 0) {
    return "";
  }

  strLengths = (unsigned int *) calloc(strsSize, sizeof(unsigned int));

  for (i = 0; i < strsSize; i++) {
    strLengths[i] = strlen(strs[i]);

    if (strLengths[i] == 0) {
      return "";
    }
  }

  commonPrefixMaxLength = max(strLengths, strsSize);
  commonPrefix = (char *) calloc(commonPrefixMaxLength + 1, sizeof(char));
  
  strcpy(commonPrefix, strs[0]);

  for (i = 1; i < strsSize; i++) {
    j = 0;
    while (strs[i][j] != '\0' && commonPrefix[j] != '\0') {
      if (strs[i][j] != commonPrefix[j]) {
        memset(commonPrefix + j, '\0', commonPrefixMaxLength - j);

        break;
      }

      j++;
    }

    memset(commonPrefix + j, '\0', commonPrefixMaxLength - j);

    if (!strcmp(commonPrefix, "")) {
      free(commonPrefix);

      return "";
    }
  }

  return commonPrefix;
}

