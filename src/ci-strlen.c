#define NULL 0

unsigned int ci_strlen(char *str) {
  if (str  == NULL) {
    return 0;
  }

  unsigned int lenth = 0;
    
  while (*str) {
      ++lenth;
      ++str;
    }

  return(lenth);
}

