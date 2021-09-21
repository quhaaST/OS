#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#define BUFFER_SIZE 8

int buffer[BUFFER_SIZE], count = 0;
bool consumer_state = true, // true stands for active, false for sleep
producer_state = true;

// sleep process 
void sleep_actor(char actor) {
    if (actor == 'P') {
        producer_state = false;
    } else if (actor == 'C') {
        consumer_state = false;
    } else {
        printf("Unknown actor.\n");
    }
}

// wake up process
void wake_up_actor(char actor) {
    if (actor == 'P') {
        producer_state = true;
    } else if (actor == 'C') {
        consumer_state = true;
    } else {
        printf("Unknown actor.\n");
    }
}

// consumer logic
_Noreturn void * consumer() {
    while (true) {
        if (consumer_state) {
            if (count == 0) {
                sleep_actor('C');
            } else {
                buffer[count] = 0;
                count--;


            }
        }
        if (!producer_state && count < BUFFER_SIZE) {
            wake_up_actor('P');
        }
    }
}

// producer logic
_Noreturn void * producer() {
    while (true) {
        if (producer_state) {
            if (count == BUFFER_SIZE - 1) {
                sleep_actor('P');
            } else {
                buffer[count] = 1; // some item by producer
                count++;
            }
        }

        if (!consumer_state && count > 0) {
            wake_up_actor('C');
        }
    }
}

// thread to output all needed information once a minute
_Noreturn void * info_thread() {
    while (true) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", buffer[i]);
        }
        printf("| %d %d - P, %d - C\n", count, producer_state, consumer_state);
        sleep(60); // one minute break in output
    }
}

int main() {
	
	for (int i = 0; i < BUFFER_SIZE; i++) buffer[i] = 0; // initial values for a buffer

    pthread_t p_thread, c_thread, output_thread;

    pthread_create(&c_thread, NULL, consumer, NULL);
    pthread_create(&p_thread, NULL, producer, NULL);
    pthread_create(&output_thread, NULL, info_thread, NULL);

    pthread_exit(NULL);
}
