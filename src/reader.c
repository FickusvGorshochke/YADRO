#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    key_t key = ftok("shmfile", 65);  
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *str = (char*) shmat(shmid, NULL, 0);


    if (strcmp(str, "-1")==0) {
        perror("shmat");
        exit(1);
    }

    sprintf(str, "hello world");

    printf("%ld\n", key);

    return 0;
}
