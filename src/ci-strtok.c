#define NULL 0

char *ci_strtok(char *str, const char *delim){
  char* buffer;

  if(str != NULL) {
    buffer = str;
  }
  if(buffer[0] == '\0') {
    return NULL;
  }
 
  char *result = buffer, *b;
  const char *d;
 
  for(b = buffer; *b != '\0'; b++) {
    for(d = delim; *d != '\0'; d++) {
      if(*b == *d) {
	*b = '\0';
	buffer = b+1;

	if(b == result) { 
	  result++; 
	  continue; 
	}
	return result;
      }
    }
  }
 
  return result;
}

