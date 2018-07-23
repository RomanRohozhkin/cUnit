#ifndef TEST_INFO
#define TEST_INFO

typedef struct TestInfo {
    char *name;
    int isFailed;
    char *message;
} TestInfo;


TestInfo *testInfo_create(char *testName);
void testInfo_delete(TestInfo *instance);
void setUp(char *testName);
void tearDown();

#endif

