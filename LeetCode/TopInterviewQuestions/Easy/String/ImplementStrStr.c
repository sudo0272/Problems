#include <stddef.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
  size_t haystackLength = strlen(haystack);
  size_t needleLength = strlen(needle);
  unsigned long long haystackPartHash;
  unsigned long long needleHash;
  unsigned int i;
  unsigned int j;
  
  if (needleLength > haystackLength) {
    return -1;
  }

  if (   needleLength == 0
      || haystackLength == 0) {
    return 0;
  }

  haystackPartHash = 0;
  needleHash = 0;
  for (i = 0; i < needleLength; i++) {
    needleHash = (needleHash << 1) + needle[i];
    haystackPartHash = (haystackPartHash << 1) + haystack[i];
  }

  for (i = 0; i <= haystackLength - needleLength; i++) {
    if (haystackPartHash == needleHash) {
      for (j = 0; j < needleLength; j++) {
        if (haystack[j + i] != needle[j]) {
          break;
        }
      }

      if (j == needleLength) {
        return i;
      }
    }

    haystackPartHash =
        ((haystackPartHash - (haystack[i] << (needleLength - 1))) << 1)
      + haystack[i + needleLength];
  }

  return -1;
}

