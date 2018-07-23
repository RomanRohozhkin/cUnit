#include "unit.h"
#include "ci_testInfo.h"
#include "ci_linkedList.h"

void fail(allTests, message, isFailed) {
    testInfo_add_status(allTests, message, isFailed);
}


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\x1b[36m"

#define FAILMESSAGE  __func__"() "RED"FAILED" RESET ". In File: "__FILE__", Line: "__LINE__"\n"

#define FAIL do { fail(allTests, } while(0);



#define PASS() printf(CYAN"%d. %s() PASSED."RESET"\n", tests_run + 1, __func__)


#define _assert(test) do { if (!(test)) { FAILMESSAGE; tests_failed++; break; } PASS(); test_passed++; } while(0); tests_run++;
extern int tests_run, tests_failed, test_passed;
