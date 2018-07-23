#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include <stdlib.h>
#include "endLine.h"

void setAllocCounter();

void test_strstr_simple() {
  char str1[] = "hello World sadad";
  char str2[] = "World";
  char *res = ci_strstr(str1, str2);
  _assert(ci_strcmp(res, "World sadad") == 0);
}

void test_strstr_noStr() {
  char str1[] = "hello World sadad";
  char str2[] = "zzz";
  char *res = ci_strstr(str1, str2);
  _assert((res == NULL) == 0);
}

void test_strstr_dynMemory_simple() {
  char *str1 = string_new("hello hi bye");
  char *str2 = string_new("hi");
  char *result = ci_strstr(str1, str2);
  _assert(ci_strcmp(result, "hi bye") == 0);
  string_delete(str1);
  string_delete(str2); 
}

