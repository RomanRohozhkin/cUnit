#include <stdlib.h>
#include <stdio.h>
#include "ci_strings.h"
#include "ci_memory.h"

char *string_new(char *string) {
    if (string != NULL) {
  int len = ci_strlen(string);
  char *str = malloc(len+1);
  ci_strcpy(str, string);
  return str;
    }
    char *str = malloc(sizeof(char));
    return str;
}

void string_delete(char *string) {
  free(string);
}

