#include <stdio.h>
#include <stdlib.h>
#include "ci_testInfo.h"
#include "ci_linkedList.h"
#include "ci_memory.h"
#include "unit.h"

#define FALSE 0
#define TRUE 1

char *errorMessage;
int isFailed;
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

void testInfo_add_status(TestInfo *instance, char *message, int isFailed) {
//    int failed = testInfo_element_isFailed(instance);
//    isFailed = isFailed;
    instance->isFailed = isFailed;
    instance->message = message;
   // char *errorMessage = testInfo_element_message(instance);
   // errorMessage = string_new(message);
}

void testInfo_print_result(TestInfo *instance) {
    int Int = testInfo_element_isFailed(instance);
    printf("isfailed: %d\n", Int);
    if (testInfo_element_isFailed(instance) > 0) {
    printf("Error Message: %s", instance->message);
    } else {
        printf("PASSED");
    }
}

void testInfo_delete(TestInfo *instance) {
    string_delete(instance->name);
    free(instance);
}

void setUp(List *allTests, char *testName) {
    TestInfo *instance = testInfo_create(testName);
    list_append(allTests, instance);
}

void tearDown(List *allTests) {
    void *instance = list_pop(allTests, 0);
    testInfo_add_status(instance, errorMessage, isFailed); //insert data in unit.h enter arguments in _Assert time runnig
    char *str = testInfo_element_message(instance);
    int Int = testInfo_element_isFailed(instance);
    printf("isFailed: %d, Message: %s\n", Int, str);
    //testInfo_print_result(instance);
    isFailed = 0;
    errorMessage = "";
    testInfo_delete(instance);
    //free(errorMessage);
}

