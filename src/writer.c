#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    FILE *file = fopen("shmfile", "w");
    if (file == NULL) {
        perror("fopen failed");
        exit(1);
    }
    fclose(file);
    
    key_t key = ftok("shmfile", 65);

    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *str = (char*) shmat(shmid, (void*)0, 0);

    if (strcmp(str, "-1")==0) {
        perror("shmat");
        exit(1);
    }

    sprintf(str, "Hello world!");

    printf("%ld\n", key);

    return 0;
}
