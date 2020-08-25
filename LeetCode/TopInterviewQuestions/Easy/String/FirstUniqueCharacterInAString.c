int firstUniqChar(char * s){
  unsigned int alphabets[26] = {0, };
  char *ch;

  ch = s;
  while (*ch != '\0') {
    alphabets[*ch - 'a']++;

    ch++;
  }

  ch = s;
  while (*ch != '\0') {
    if (alphabets[*ch - 'a'] == 1) {
      return ch - s;
    }

    ch++;
  }

  return -1;
}

