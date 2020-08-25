#include <stdbool.h>

bool isAnagram(char * s, char * t){
  unsigned int sAlphabets[26] = {0, };
  unsigned int tAlphabets[26] = {0, };
  char *sCh = s;
  char *tCh = t;
  unsigned int i;

  while (*sCh != '\0' && *tCh != '\0') {
    sAlphabets[*sCh - 'a']++;
    tAlphabets[*tCh - 'a']++;

    sCh++;
    tCh++;
  }

  if (*sCh != *tCh) { // If the length of s and the length of t is same,
                      // *sCh and *tCh both must be '\0'
                      // Thus, if *sCh and *tCh are different, it means
                      // the length of s and the length of t is different
                      // and it means s isn't an anagram of t
    return false;
  }

  for (i = 0; i < 26; i++) {
    if (sAlphabets[i] != tAlphabets[i]) {
      return false;
    }
  }

  return true;
}

