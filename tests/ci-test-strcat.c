#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include <stdlib.h>
#include "endLine.h"

void setAllocCounter();

void test_strcat_simple() {
  char str1[100] = "abcdef";
  char str2[] = "ghij";
  ci_strcat(str1, str2);
  _assert(ci_strcmp(str1, "abcdefghij") == 0);
}

void test_strcat_withEmptyStr() {
  char str1[100] = "abcd";
  char str2[] = "";
  ci_strcat(str1, str2);
  _assert(ci_strcmp(str1, "abcd") == 0);
}

void test_strcat_withPasteStr() {
  char str1[100] = "1";
  ci_strcat(str1, "abcd");
  char tmp = str1[4];
  _assert((tmp == '\0') == 0);
}

void test_strcat_dynMemory_simple() {
  char *str = malloc(100);
  char *str1 = string_new("Hello");
  char *str2 = string_new(" World!");
  ci_strcat(str, str1);
  ci_strcat(str, str2);
  _assert(ci_strcmp(str, "Hello World!") == 0);
  free(str);
  string_delete(str1);
  string_delete(str2);;
}

void test_strcat_dynMemory_emptyStr() {
  char *str = malloc(100);
  char *str1 = string_new("Hello");
  char *str2 = string_new("");
  ci_strcat(str, str1);
  ci_strcat(str, str2);
  _assert(ci_strcmp(str, str1) == 0);
  free(str);
  string_delete(str1);
  string_delete(str2);
}

