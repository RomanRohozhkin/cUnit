#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include "endLine.h"

void setAllocCounter();

void test_strlen_equalSize() {
  startLine();
  char str[] = "12345";
  _assert(ci_strlen(str) == 5);
  endLine();
}

void test_strlen_emptyStr() {
  startLine();
  char str2[] = "";
  _assert(ci_strlen(str2) == 0);
  endLine();
}

void test_strlen_NULLTerminate() {
  startLine();
  char str2[] = "1\0";
  _assert(ci_strlen(str2) == 1);
  endLine();
}

void test_strlen_Null() {
  startLine();
  char *str = NULL;
  _assert(ci_strlen(str) == 0);
  endLine();
}

void test_strlen_dynMemory_Equal() {
  startLine();
  char *str = string_new("Hello");
  _assert(ci_strlen(str) == 5);
  string_delete(str);
  setAllocCounter();
  endLine();
}

void test_strlen_dynMemory_Null() {
  startLine();
  char *str = string_new("");
  _assert(ci_strlen(str) == 0);
  string_delete(str);
  setAllocCounter();
  endLine();
}

