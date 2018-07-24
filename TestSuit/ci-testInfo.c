#include <stdio.h>
#include <stdlib.h>
#include "ci_testInfo.h"
#include "ci_linkedList.h"
#include "ci_memory.h"
#include "unit.h"
#include "endLine.h"
#include <assert.h>

#define FALSE 0
#define TRUE 1

#define RED     "\033[31m"
#define CYAN    "\x1b[36m"
#define RESET   "\033[0m"

void setAllocCounter();
int getAllocCounter();
void memoryAlarm();

int tests_run, tests_failed, test_passed;

char *errorMessage;
int isFailed;

TestInfo *testInfo_create(char *testName) {
    TestInfo *instance = malloc(sizeof(TestInfo));
    instance->name = string_new(testName);
    instance->isFailed = FALSE;
    instance->message = NULL;
    
    return instance;
}

void testInfo_delete(TestInfo *instance) {
    string_delete(instance->name);
    string_delete(instance->message);
    free(instance);
}

int testInfo_element_isFailed(TestInfo *instance) {
    return instance->isFailed;
}

char *testInfo_element_message(TestInfo *instance) {
    return instance->message;
}

void testInfo_add_status(TestInfo *instance, char *message, int isFailed) {
    instance->isFailed = isFailed;
    instance->message = string_new(message);
    
}

void testInfo_print_result(TestInfo *instance) {
    startLine();
    if (testInfo_element_isFailed(instance) > 0 && getAllocCounter() > 0) {
        printf("%d. "CYAN"%s() "RESET RED"FAILED"RESET"\n", tests_run, instance->name);
        printf("%s", instance->message);
    } else if (testInfo_element_isFailed(instance) > 0) {
        printf("%d. "CYAN"%s() "RESET RED"FAILED"RESET"\n", tests_run, instance->name);
        printf("%s", instance->message);
    } else if (getAllocCounter() > 0) {
        tests_failed++;
        test_passed--;
        printf("%d. "CYAN"%s() "RESET RED"FAILED"RESET"\n", tests_run, instance->name);
        printf("%s", instance->message);
    } else {
        printf("%d. "CYAN"%s()"RESET" PASSED\n", tests_run, instance->name);
    }
    memoryAlarm();
    endLine();
}



void setUp(List *allTests, char *testName) {
    TestInfo *instance = testInfo_create(testName);
    list_append(allTests, instance);
    setAllocCounter();
}

void tearDown(List *allTests) {
  void *instance = list_pop(allTests, 0);
    testInfo_add_status(instance, errorMessage, isFailed);
    if (isFailed == 0){
        test_passed++;
    } else {
        tests_failed++;
    }
    tests_run++;
    testInfo_print_result(instance);
    testInfo_delete(instance);
    isFailed = 0;
}

