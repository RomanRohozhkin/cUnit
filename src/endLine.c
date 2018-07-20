#include <stdio.h>
#include "endLine.h"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

void startLine() {
 printf(MAGENTA"---------"RESET"START TEST"MAGENTA"-------\n"RESET);
}

void endLine() {
 printf(MAGENTA"----------"RESET"END TEST"MAGENTA"--------\n\n"RESET);
}
