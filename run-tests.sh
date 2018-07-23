#!/bin/bash

for FILE in `find ./tests -type f -name "ci-test-*.c"`
do
FUNCS_COUNT=$(cat $FILE | grep -c "test_"*)
FUNCS=$(cat $FILE| grep -Rh 'test_*' >> funcs.h )
FILES=${FILES}" "$FILE
done

for CI in `find ./src -type f -name "ci-str*.c"`
do
CI_STR=${CI_STR}" "$CI
done

sed 's/{$//' funcs.h  > test_funcs.h
sed 's/$/;/' test_funcs.h > tests_signatures.h

sed 's/^.*\(test.*;\).*$/\1/' tests_signatures.h > all_tests.h
sed 's/(.*//' all_tests.h > funcs_names.h

function add {
while IFS= read line
do
ALINE=$(echo $line | sed 's/(.*//')
echo "setUp(allTests, \"$ALINE\");"
echo "$line"
echo "tearDown(allTests);"
echo
done < all_tests.h
}
add > call_all.h

echo "#define RESET   \"\033[0m\"
#define RED     \"\033[31m\"
#include <stdio.h>
#include \"tests_signatures.h\"
#include \"./TestSuit/ci_testInfo.h\"
#include \"./src/ci_linkedList.h\"
#pragma clang diagnostic ignored \"-Wformat-extra-args\"

int tests_run, tests_failed, test_passed;
char *errorMessage;

void all() {
List *allTests = list_create();
$(cat call_all.h)
}
int main() {

printf(\"\\\\n~~~~~~~~~~TESTS START~~~~~~~~~\\\\n\");
printf(\"\\\\n\");
all();
printf(\"\\\\n~~~~~~~~~~TESTS END~~~~~~~~~~~\\\\n\");
if (tests_failed == 0) {
printf(\"\\\\nALL TESTS ARE PASSED\\\\n\");
}
printf(\"\\\\nTests PASSED: %d/\"RED\"%d\"RESET\".\\\\n\", test_passed, tests_run);
printf(\"\\\\nTests FAILED: \"RED\"%d\"RESET\"/%d.\\\\n\\\\n\", tests_failed, tests_run);
return 0;
}" > ci-all-tests.c

clang -dynamiclib -undefined suppress -flat_namespace -std=c99 -fPIC -O2 ./TestSuit/malloc.c -o libhackmalloc.dylib
#cp ./libhackmalloc.dylib ./tests/libhackmalloc.dylib

clang -o run ci-all-tests.c $FILES $CI_STR -std=c99 -L. -lhackmalloc -O2 ./src/endLine.c ./src/ci-memoryAlloc.c ./src/ci-linkedList.c ./TestSuit/ci-testInfo.c -Isrc/ -ITestSuit 
./run

rm -rf libhackmalloc.dylib
rm funcs.h test_funcs.h tests_signatures.h  ci-all-tests.c run #all_tests.h
find . -type f -name '*~' -delete
