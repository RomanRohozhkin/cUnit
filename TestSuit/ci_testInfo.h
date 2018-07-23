#ifndef TEST_INFO
#define TEST_INFO
#include "ci_linkedList.h"

typedef struct TestInfo {
    char *name;
    int isFailed;
    char *message;
} TestInfo;


TestInfo *testInfo_create(char *testName);
void testInfo_delete(TestInfo *instance);
void setUp(List *allTests, char *testName);
void tearDown(List *allTests);

#endif

