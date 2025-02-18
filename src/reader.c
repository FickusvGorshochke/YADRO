#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {


    
    key_t key;
    scanf("%ld", &key);
    printf("key: %ld\n", &key);
    int shmid = shmget(key, 1024, 0666);
    printf("shmid_read: %d\n", shmid);

    
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    char *str = (char*) shmat(shmid, NULL, 0);

    if (strcmp(str, "-1")==0) {
        perror("shmat");
        exit(1);
    }

    printf("Data read from memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);


    return 0;
}

