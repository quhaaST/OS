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
    while (true) {
        int lastPressed = 0;
        read(fileDescriptor, &inputEvent, sizeof inputEvent);
        if (inputEvent.type == 1) {
            printf("%s 0x%04x (%d)\n", types[inputEvent.value], inputEvent.code, inputEvent.code);
        }
    }
    close(fileDescriptor);
    fflush(stdout);
}
