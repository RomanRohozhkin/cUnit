#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ci_testInfo.h"
#include "ci_linkedList.h"
#include "ci_memory.h"

#define FALSE 0
#define TRUE 1

static List *allTests = list_create();

TestInfo *testInfo_create(char *testName, char *message) {
    TestInfo *instance = malloc(sizeof(TestInfo));
    instance->name = string_new(testName);
    instance->isFailed = FALSE;
    instance->message = string_new(message);
    
    return instance;
}

void testInfo_delete(TestInfo *instance) {
    string_delete(instance->name);
    string_delete(instance->message);
    free(instance);
}

void setUp(char *testName) {
    TestInfo *instance = testInfo_create(testName, ...);
    list_append(allTests, instance); ?????!!!! 
}

void tearDown() {
    
}

