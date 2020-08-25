#include <string.h>

int firstUniqChar(char * s){
  unsigned int alphabets[26] = {0, };
  unsigned int i;
  size_t sLength = strlen(s);

  for (i = 0; i < sLength; i++) {
    alphabets[s[i] - 'a']++;
  }

  for (i = 0; i < sLength; i++) {
    if (alphabets[s[i] - 'a'] == 1) {
      return i;
    }
  }

  return -1;
}

