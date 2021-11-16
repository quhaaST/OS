#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <memory.h>

int main() {
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Cannot open the file!\n");
        return -1;
    }
    int buff, RESOURCE_AMOUNT = 3, PROCESS_AMOUNT = 5;
    int resource_amount[RESOURCE_AMOUNT], resource_available[RESOURCE_AMOUNT],
        current_alloc[PROCESS_AMOUNT][RESOURCE_AMOUNT], request[PROCESS_AMOUNT][RESOURCE_AMOUNT];
    bool *process_state = malloc(sizeof (int) * PROCESS_AMOUNT);
    memset(process_state, false, PROCESS_AMOUNT);
    for (int i = 0; i < RESOURCE_AMOUNT; i++) {
        fscanf(fp, "%d", &buff);
        resource_amount[i] = buff;
    }

    for (int i = 0; i < RESOURCE_AMOUNT; i++) {
        fscanf(fp, "%d", &buff);
        resource_available[i] = buff;
    }

    for (int i = 0; i < PROCESS_AMOUNT; i++) {
        for (int j = 0; j < RESOURCE_AMOUNT; j++) {
            fscanf(fp, "%d", &buff);
            current_alloc[i][j] = buff;
        }
    }

    for (int i = 0; i < PROCESS_AMOUNT; i++) {
        for (int j = 0; j < RESOURCE_AMOUNT; j++) {
            fscanf(fp, "%d", &buff);
            request[i][j] = buff;
        }
    }

    bool changes = true;
    while (changes) {
        changes = false;
        for (int i = 0; i < PROCESS_AMOUNT; i++) {
            if (process_state[i]) continue;
            bool possible = true;
            for (int j = 0; j < RESOURCE_AMOUNT; j++) {
                if (request[i][j] > resource_available[j]) {
                    possible = false;
                }
            }
            if (possible) {
                for (int j = 0; j < RESOURCE_AMOUNT; j++) {
                    resource_available[j] += current_alloc[i][j];
                }
                process_state[i] = true;
                changes = true;
                i = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < PROCESS_AMOUNT; i++) {
        if (!process_state[i]) {
            printf("Deadlocked process: %d\n", (i + 1));
            cnt++;
        }
    }

    if (cnt == 0) {
        printf("No deadlock is detected!\n");
    }
    fclose(fp);
}