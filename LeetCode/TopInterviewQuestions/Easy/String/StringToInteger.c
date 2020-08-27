#include <ctype.h>

int toNumber(int current) {
  return current - '0';
}

int myAtoi(char *str) {
  int result;
  int digits;
  int isNegative;
  int current;

  // skip whitespace currentaracters
  while (str[current] != '\0' && str[current] == ' ') {
    current++;
  }

  result = 0;
  digits = 0;
  isNegative = 0;
  if (str[current] == '\0') {
    return 0;
  } else if (str[current] == '-') {
    isNegative = 1;
    current++;
  } else if (str[current] == '+') {
    current++;
  }

  // skips zeros
  while (str[current] != '\0' && str[current] == '0') {
    current++;
  }

  while (str[current] != '\0' && isdigit(str[current])) {
    if (result < 214748364) {
      if (digits == 9) {
        if (isdigit(str[current + 1])) {
          if (isNegative) {
            return -2147483648;
          } else {
            return 2147483647;
          }
        } else {
          if (isNegative) {
            return -result * 10 - toNumber(str[current]);
          } else {
            return result * 10 + toNumber(str[current]);
          }
        }
      } else {
        result = result * 10 + toNumber(str[current]);

        digits++;
        current++;
      }
    } else if (result == 214748364) {
      if (isNegative) {
        if (str[current] <= '8') {
          return -result * 10 - toNumber(str[current]);
        } else {
          return -2147483648;
        }
      } else {
        if (str[current] <= '7') {
          return result * 10 + toNumber(str[current]);
        } else {
          return 2147483647;
        }
      }
    } else {
      if (isNegative) {
        return -2147483648;
      } else {
        return 2147483647;
      }
    }
  }
  
  if (isNegative) {
    return -result;
  } else {
    return result;
  }
}

