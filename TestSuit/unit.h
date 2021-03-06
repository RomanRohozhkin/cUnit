#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\x1b[36m"
#include <strings.h>
#include <stdlib.h>

char *errorMessageTmp;

#define _assert(test) do { if (!(test)) { isFailed++;  if(isFailed == 1) { asprintf(&errorMessage, "In File: %s, Line: %d\n", __FILE__, __LINE__);} else if (isFailed > 1) { asprintf(&errorMessageTmp, "In File: %s, Line: %d\n",  __FILE__, __LINE__);  strcat(errorMessage, errorMessageTmp); strcpy(errorMessageTmp, "");}}  break;  } while(0);

extern int tests_run, tests_failed, test_passed, isFailed;
extern char *errorMessage;
