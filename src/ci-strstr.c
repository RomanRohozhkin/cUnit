const char *ci_strstr(const char *haystack, const char *needle) {
  
  int i, j;
  const char *result;
  
  for (i = 0; haystack[i] != '\0'; i++) {
    for (j = 0; needle[j] != '\0'; j++) {
      if (haystack[i] == needle[j]) {

        result = &haystack[i];
        continue;
      }
      break;
    }
  }
  return result;
}

