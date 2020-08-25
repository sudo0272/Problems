int firstUniqChar(char * s) {
  unsigned int alphabets[26] = {0, };
  unsigned int sLength = 0;
  unsigned int i;

  while (s[sLength] != '\0') {
    alphabets[s[sLength] - 'a']++;

    sLength++;
  }

  for (i = 0; i < sLength; i++) {
    if (alphabets[s[i] - 'a'] == 1) {
      return i;
    }
  }

  return -1;
}

