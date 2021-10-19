#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

const int MAX_VALUE = 32768, NUMBER_BITS = 16; // base values

// representation of a page frame
typedef struct Frame {
    int cache;
    int counter;
} Frame;

// creation of a page frame
Frame* create_frame () {
    Frame *frame = malloc(sizeof (Frame));
    frame->cache = -1;
    frame->counter = 0;
    return frame;
}

// updating the counter if reference bit is 0 (if page is different from the current one)
void decrease_counter(Frame *frame) {
    frame->counter >>= 1;
}

// setting a new page into the frame
void set_new_page(Frame *frame, int page_number) {
    frame->cache = page_number;
    frame->counter = MAX_VALUE;
}

// updating the counter if reference bit is 1 (if page is the same as the current one)
void reset_page(Frame *frame) {
    frame->counter |= 1 << (NUMBER_BITS - 1);
}

// show the current conditions of the page frames
void print_state(Frame *frames[], int size) {
    for (int i = 0; i < size; i++) {
        printf("i = %d  id = %d %d\n", i, frames[i]->cache, frames[i]->counter);
    }
}

int main() {
    int frames_number;
    bool valid_input = false;
    while (!valid_input) { // check for a valid number of page frames
        printf("Enter the number of page frames: ");
        scanf("%d", &frames_number);
        if (frames_number > 0) valid_input = true;
    }

    // initialize the page frames array
    Frame* frames[frames_number];
    for (int i = 0; i < frames_number; i++) {
        frames[i] = create_frame();
    }

    FILE *fp;
    fp = fopen("Lab09input.txt", "r");

    int hit_number = 0, miss_number = 0;
    while (!feof(fp)) { // while the file is not fully read
        int reference;
        fscanf(fp, "%d", &reference);

        bool placed = false;

        for (int i = 0; i < frames_number; i++) { // age all frames and check if a reference is present
            decrease_counter(frames[i]);
            if (frames[i]->cache == reference) {
                reset_page(frames[i]);
                placed = true;
            }
        }

        if (!placed) { // check if we still need to find a frame for a new reference
            int least_cnt = MAX_VALUE + 1, least_index = -1;
            for (int i = 0; i < frames_number; i++) {
                if (frames[i]->counter == least_cnt && frames[least_index]->cache != -1 && frames[i]->cache == -1) { // fill empty frames first
                    least_index = i;
                }
                if (frames[i]->counter < least_cnt) {
                    least_cnt = frames[i]->counter;
                    least_index = i;
                }
            }
            set_new_page(frames[least_index], reference);
        }

        if (placed) {
            hit_number++;
        } else {
            miss_number++;
        }

        print_state(frames, frames_number);
        printf("Current page number: %d\n\n", reference);
    }

    printf("hit = %d, miss = %d, ratio = %f", hit_number, miss_number, hit_number * 1.0 / miss_number);

    fclose(fp);
}
