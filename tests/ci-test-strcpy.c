#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include <stdlib.h> 
#include "endLine.h"

void setAllocCounter();

void test_strcpy_toEmptyStr() {
  char str1[100];
  char str2[] = "ghij";
  ci_strcpy(str1, str2);
  _assert(ci_strcmp(str1, str2) == 0)
}

void test_strcpy_toNotEmptyStr() {
  char str1[100] = "abcd";
  char str2[] = "aaaaaaa";
  ci_strcpy(str1, str2);
  _assert(ci_strcmp(str1, str2) == 0);
}

void test_strcpy_dynMemory_toEmptyStr() {
  char *str1 = malloc(100);
  char *str2 = string_new("hello");
  ci_strcpy(str1, str2);
  _assert(ci_strcmp(str1, str2) == 0);
  free(str1);
  string_delete(str2);
}

