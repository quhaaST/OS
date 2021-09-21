#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myThread(int pos) {
    printf("Hello from myThread #%d\n", pos);
    pthread_exit(NULL);
}

int main() {
	int N;
	printf("Type the number of thread to be created: ");
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
        pthread_t pthread;
        if(pthread_create(&pthread, NULL, myThread, (i+1))) {
            printf("Fuck\n");
        } else {
            printf("Thread #%d was created successfully! \n", i + 1);
        }
        pthread_join(pthread, NULL);
	}
}


