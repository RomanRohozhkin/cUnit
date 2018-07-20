#include "ci_strings.h"
#include "unit.h"
#include <stdio.h>
#include "ci_linkedList.h"
#include <stdlib.h>
#include "endLine.h"

void setAllocCounter();

void test_linkedList_creation() {
  startLine();
  List *list = list_create();
  _assert(list != NULL);
  list_delete(list);
  setAllocCounter();
  endLine();
}

void test_linkedList_append() {
  startLine();
  List *list = list_create();
  list_append(list, "one");
  _assert(ci_strcmp(list->first->data, "one") == 0);
  list_delete(list);
  setAllocCounter();
  endLine();
}

void test_linkeList_count() {
  startLine();
  List *list = list_create();
  list_append(list, "one");
  list_append(list, "two");
  list_append(list, "three");
  list_append(list, "four");
  _assert(list_length(list) == 4);
  list_delete(list);
  setAllocCounter();
  endLine();
}

void test_linkedList_insert() {
  startLine();
  List *list = list_create();
  list_append(list, "one");
  list_append(list, "two");
  list_append(list, "three");
  list_insert(list, 2, "two.2");
  _assert(ci_strcmp(list_get(list, 2), "two.2") == 0);
  list_delete(list);
  setAllocCounter();
  endLine();
}

void test_linkedList_remove() {
  startLine();
  List *list = list_create();
  list_append(list, "one");
  list_append(list, "two");
  list_append(list, "three");
  list_removeElement(list, 1);
  _assert(ci_strcmp(list_get(list, 1), "three") == 0);
  list_delete(list);
  setAllocCounter();
  endLine();
}

void test_linkedList_pop() {
  startLine();
  List *list = list_create();
  list_append(list, "one");
  list_append(list, "two");
  list_append(list, "three");
  char *str = list_pop(list, 1);
  _assert(ci_strcmp("two", str) == 0);
  _assert(list_length(list) == 2);
  //list_delete(list);
  setAllocCounter();
  endLine();
}

