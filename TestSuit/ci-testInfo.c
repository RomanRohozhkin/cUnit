#include <stdio.h>
#include <stdlib.h>
#include "ci_testInfo.h"
#include "ci_linkedList.h"
#include "ci_memory.h"

#define FALSE 0
#define TRUE 1

//static List *allTests = list_create();

TestInfo *testInfo_create(char *testName) {
    TestInfo *instance = malloc(sizeof(TestInfo));
    instance->name = string_new(testName);
    instance->isFailed = FALSE;
    instance->message = NULL;
    
    return instance;
}

int testInfo_element_isFailed(TestInfo *instance) {
    return instance->isFailed;
}

char *testInfo_element_message(TestInfo *instance) {
    return instance->message;
}

void testInfo_add_status(List *allTests, char *message, int isFailed) {
    void *instance = list_get(allTests, 0);
    int failed = testInfo_element_isFailed(instance);
    isFailed = isFailed;
    char *errorMessage = testInfo_element_message(instance);
    errorMessage = message;
    
    printf("isFailed: %d\nMessage: %s\n", isFailed, errorMessage);
}



void testInfo_delete(TestInfo *instance) {
    string_delete(instance->name);
   // string_delete(instance->message);
    free(instance);
}

void setUp(List *allTests, char *testName) {
    TestInfo *instance = testInfo_create(testName);
    list_append(allTests, instance);
}

void tearDown(List *allTests) {
    testInfo_add_status(allTests, "error in line 12:", 1);
    void *instance = list_pop(allTests, 0);
    testInfo_delete(instance);
}

