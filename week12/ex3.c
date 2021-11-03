#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

const char *types[3] = {
        "RELEASED",
        "PRESSED",
        "REPEATED"
};

int main() {
    const char *path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event inputEvent;

    int fileDescriptor = open(path, O_RDONLY);

    if (fileDescriptor == -1) {
        printf("Cannot open %s", path);
        return -1;
    }

    bool keysPressed[40];

    while (true) {
        read(fileDescriptor, &inputEvent, sizeof inputEvent);
        if (inputEvent.type == 1) {
            if (inputEvent.value == 1 || inputEvent.value == 2) {
                keysPressed[inputEvent.code - 16] = true;
            } else {
                keysPressed[inputEvent.code - 16] = false;
            }
        }

        // check for P + E shortcut
        // keysPressed[2] stands for E, keysPressed[9] stands for P
        if (keysPressed[2] && keysPressed[9]) {
            keysPressed[2] = false;
            keysPressed[9] = false;
            printf("I passed the Exam!\n");
        }

        // check for C + A + P shortcut
        if (keysPressed[30] && keysPressed[14] && keysPressed[9]) {
            keysPressed[9] = false;
            keysPressed[14] = false;
            keysPressed[30] = false;
            printf("Get some cappuccino!\n");
        }

        // check for U + P + D shortcut
        if (keysPressed[6] && keysPressed[9] && keysPressed[16]) {
            keysPressed[6] = false;
            keysPressed[9] = false;
            keysPressed[16] = false;
            printf("Some updates in the Moodle!\n");
        }
    }
    close(fileDescriptor);
    fflush(stdout);
}
