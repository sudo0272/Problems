#include <stddef.h>

int strStr(char *haystack, char *needle) {
  size_t commonNeedleLength;

  commonNeedleLength = 1;
  while (needle[commonNeedleLength] != '\0') {
    if (needle[commonNeedleLength] != needle[commonNeedleLength - 1]) {
      break;
    }
  }

  return 0; // dump
}

