#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    pid_t pid;

    printf("begin\n");

    fflush(NULL); //刷新所有流
    pid = fork();
    if(pid < 0){
        perror("fork()");
        exit(1);
    }

    if(pid == 0){
        execl("/bin/date","fff",NULL);  //可以不关心 argv[0]
        perror("execl()");
        exit(1);
    }

    //sleep(20);
    printf("wait\n");
    wait(NULL);
    //sleep(20);
  //  system("date");
    printf("end\n");
    exit(0);
}