//
//  main.cpp
//  treads
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <iostream>
using namespace std;

void * thread_func(void *arg) {
    int i;
    int loc_id = * (int *) arg;
    for (i = 0; i < 4; i++) {
        printf("Stream %i working\n", loc_id);
        sleep (1);
    }
    return 0;
}


int main(int argc, char * argv[]) {
    int id1, id2, result;
    pthread_t thread1, thread2;
    
    id1 = 1;
    result = pthread_create(&thread1, NULL, thread_func, &id1);
    if (result != 0) {
        perror("Create 1 stream!");
        return EXIT_FAILURE;
    }
    
    id2 = 2;
    result = pthread_create(&thread2, NULL, thread_func, &id2);
    if (result != 0) {
        perror("Create 2 stream!");
        return EXIT_FAILURE;
    }
    
    sleep (2);
    printf("Reead..\n");
    
    result = pthread_join(thread1, NULL);
    if (result != 0) {
        perror("Read 1 stream");
        return EXIT_FAILURE;
    }
    
    result = pthread_join(thread2, NULL);
    if (result != 0) {
        perror ("Read 2 stream");
        return EXIT_FAILURE;
    }
    
    printf("Done\n");
    return EXIT_SUCCESS;
}



