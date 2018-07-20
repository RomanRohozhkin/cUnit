#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\x1b[36m"
#define FAIL() printf("%d. %s() "RED"FAILED" RESET ". In File: %s, Line: %d\n", tests_run + 1, __func__, __FILE__, __LINE__)
#define PASS() printf(CYAN"%d. %s() PASSED."RESET"\n", tests_run + 1, __func__)
#define _assert(test) do { if (!(test)) { FAIL(); tests_failed++; break; } PASS(); test_passed++; } while(0); tests_run++;
extern int tests_run, tests_failed, test_passed;
