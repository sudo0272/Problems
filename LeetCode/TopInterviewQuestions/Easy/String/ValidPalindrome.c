#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char * s){
  const size_t sLength = strlen(s);
  unsigned int left;
  int right;
  
  if (sLength == 0 || sLength == 1) {
    return true;
  }

  left = 0;
  right = sLength - 1;

  while (left < right) {
    while (left < sLength) {
      if (isalnum(s[left])) {
        break;
      } else {
        left++;
      }
    }

    while (right >= 0) {
      if (isalnum(s[right])) {
        break;
      } else {
        right--;
      }
    }

    if (left == sLength || right == -1) {
      return true;
    } else if (tolower(s[left]) != tolower(s[right])) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}

