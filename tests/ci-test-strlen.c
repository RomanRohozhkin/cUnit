#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"

void setAllocCounter();

void test_strlen_equalSize() {
  char str[] = "12345";
  _assert(ci_strlen(str) == 5);
}

void test_strlen_emptyStr() {
  char str2[] = "";
  _assert(ci_strlen(str2) == 0);
}

void test_strlen_NULLTerminate() {
  char str2[] = "1\0";
  _assert(ci_strlen(str2) == 1);
}

void test_strlen_Null() {
  char *str = NULL;
  _assert(ci_strlen(str) == 0);
}

void test_strlen_dynMemory_Equal() {
  char *str = string_new("Hello");
  _assert(ci_strlen(str) == 5);
  string_delete(str);
}

void test_strlen_dynMemory_Null() {
  char *str = string_new("");
  _assert(ci_strlen(str) == 0);
  string_delete(str);
}

