#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include <stdlib.h>
#include "endLine.h"

void setAllocCounter();

void test_strtok_simple() {
  char str1[] = "hello World sadad";
  char str2[] = "W";
  char *res = ci_strtok(str1, str2);
  _assert(ci_strcmp(res, "hello ") == 0);
}

void test_strtok_noMatch() {
  char str1[] = "hello World sadad";
  char str2[] = "zzz";
  char *res = ci_strtok(str1, str2);
  _assert(ci_strcmp(res, str1) == 0);
}

void test_strtok_dynMemory_simple() {
  char *str1 = string_new("hello World sadad");
  char *str2 = string_new("W");
  char *result = ci_strtok(str1, str2);
  _assert(ci_strcmp(result, "hello ") == 0);
  string_delete(str1);
  string_delete(str2);
}

void test_strtok_dynMemory_noMatch() {
  char *str1 = string_new("hello World sadad");
  char *str2 = string_new("zzz");
  char *result = ci_strtok(str1, str2);
  _assert(ci_strcmp(result, str1) == 0);
  string_delete(str1);
  string_delete(str2);
}

