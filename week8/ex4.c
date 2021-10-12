#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int DURATION = 10, PAUSE = 1;
    size_t SPACE = 256 * 1024 * 1024; // allocate 256MB for the greater clarity
    for (int i = 0; i < DURATION / PAUSE; i++) {
        int* array = (int*) malloc(SPACE);
        memset(array, 0, SPACE);
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
}
