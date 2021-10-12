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
 * When this program is running, the SI parameter is increased (100-1000 on average).
 * At the same time, SO parameter is mostly staying around 0, sometimes going to a few hundreds.
 */