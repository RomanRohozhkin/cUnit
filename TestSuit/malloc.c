#define _GNU_SOURCE
#define YEL  "\x1B[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
#include <stdio.h>
#include <dlfcn.h>

static int sAllocCounter = 0;

void* malloc(size_t size) {
    void *p = ((void*(*)(size_t))dlsym (RTLD_NEXT, "malloc"))(size);
    sAllocCounter += 1;
     return p;
}

void free (void *ptr) {
    ((void(*)(void*))dlsym(RTLD_NEXT, "free"))(ptr);
    sAllocCounter -= 1;
}

void memoryAlarm() {
    if (sAllocCounter != 0) {
        printf(RED"%d"RESET" memory "RED"LEAK(s)"RESET" in current Function\n", sAllocCounter);
    } else {
        printf(YEL"NO LEAKS"RESET"\n");
    }
}

void setAllocCounter() {
    memoryAlarm();
    sAllocCounter = 0;
}
