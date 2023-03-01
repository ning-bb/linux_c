#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define MEMSIZE 1024

int main()
{
    int shmid;
    pid_t pid;
    char *ptr = NULL;

    shmid = shmget(IPC_PRIVATE,MEMSIZE,0600);
    if(shmid < 0){
        perror("shmget():");
        exit(1);
    }

    pid = fork();
    if(pid < 0){
        perror("fork():");
        exit(1);
    }

    if(pid == 0){ //子进程代码空间
        ptr = shmat(shmid,NULL,0);
        if(ptr == (void *)-1){
            perror("child shmat():");
            exit(1);
        }
        strcpy(ptr,"Hello!");
        shmdt(ptr);
        exit(0);
    }
    else{
        wait(NULL);
        ptr = shmat(shmid,NULL,0);
        if(ptr == (void *)-1){
            perror("parent shmat():");
            exit(1);
        }
        fprintf(stdout,"%s\n",ptr);
        shmdt(ptr);
        //fprintf(stdout,"aa %s",ptr);
        shmctl(shmid,IPC_RMID,NULL);
        exit(0);
    }
    exit(0);
}