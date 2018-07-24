#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_memory.h"
#include <stdlib.h>
#include "endLine.h"

void setAllocCounter();

void test_strcmp_secondBigger() {
  _assert(ci_strcmp("", "1234") == -1);
}

void test_strcmp_firstBigger() {
    _assert(ci_strcmp("1234", "") == 1);
}

void test_strcmp_dynMemory_firstBigger() {
  char *str = string_new("");
  char *str2 = string_new("1234");
  _assert(ci_strcmp(str, str2) == -1);
  string_delete(str);
  string_delete(str2);
}

void test_strcmp_dynMemory_secondBigger() {
  char *str = string_new("1234");
  char *str2 = string_new("");
  _assert(ci_strcmp(str, str2) == 1);
  string_delete(str);
  string_delete(str2);
}

