inline void swap(char *a, char*b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void reverseString(char* s, int sSize){
  unsigned int r = 0;
  unsigned int l = sSize - 1;

  if (sSize == 0) {
    return;
  }

  while (r < l) {
    swap(&s[r], &s[l]);
    r++;
    l--;
  }
}

