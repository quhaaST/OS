#include <memory.h>
#include <malloc.h>
#include <unistd.h>

int main() {
    int DURATION = 10, PAUSE = 1;
    size_t SPACE = 512 * 1024 * 1024; // allocate 512MB for the greater clarity

    for (int i = 0; i < DURATION / PAUSE; i++) {
        int* array = (int*) malloc(SPACE);
        memset(array, 0, SPACE);
        sleep(1);
    }
}

/*
 * When this program is running, the free command shows the process ex3 which is using 0-5GB RES,
 * and showing increasing %CPU and %MEM (8.6 - 20 and 20-60 respectively)
 */
