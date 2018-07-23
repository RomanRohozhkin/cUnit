#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\x1b[36m"
#include <strings.h>
#include <stdlib.h>

//#define FAIL() printf("%d. %s() "RED"FAILED" RESET ". In File: %s, Line: %d\n", tests_run + 1, __func__, __FILE__, __LINE__)

//#define PASS() printf(CYAN"%d. %s() PASSED."RESET"\n", tests_run + 1, __func__)

char *errorMessage1;

#define _assert(test) do { if (!(test)) { isFailed++; if(isFailed == 1) {asprintf(&errorMessage, "In File: %s, Line: %d\n", __FILE__, __LINE__); tests_failed++;  tests_run++;} else {asprintf(&errorMessage1, "In File: %s, Line: %d\n",  __FILE__, __LINE__); strcat(errorMessage, errorMessage1); free(errorMessage1); } break;} else { isFailed=0; test_passed++;  tests_run++;}} while(0);

extern int tests_run, tests_failed, test_passed, isFailed;
extern char *errorMessage;


