int reverse(int x) {
  int result = 0;
  int digit = 0;

  while (x != 0) {
    if (-214748364 < result && result < 214748364) {
      if (digit == 9) {
        return (result  * 10) + x % 10;
      } else {
        result = (result  * 10) + x % 10;

        digit++;

        x /= 10;
      }
    } else if (result == -214748364) {
      if (x % 10 <= 8) {
        return result * 10 + x % 10;
      } else {
        return 0;
      }
    } else if (result == 214748364) {
      if (x % 10 <= 7) {
        return result * 10 + x % 10;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  }

  return result;
}

