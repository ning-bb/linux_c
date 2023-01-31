#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LEFT 30000000
#define RIGHT 30000200
#define FORK_N  3

//获取质数
int main(void)
{
    pid_t pid;
    uid_t uid;
    int i,j,mark,n;
    fprintf(stdout,"fu uid = %u\n",getuid());

    for(n = 0;n < FORK_N;n++){
        pid = fork();
        if(pid < 0){
            perror("fork()");
            while(n--)
                wait(NULL);
            
            exit(1);
        }

        if(pid == 0){
            for(i=LEFT+n;i<RIGHT;i+=FORK_N){
                mark = 1;
                for(j = 2;j<i/2;j++){
                    if(i%j == 0){
                        mark = 0;
                        break;
                    }
                }

                if(mark == 1){
                    fprintf(stdout,"[%d]%d is a prime number!\n",n,i);
                    fprintf(stdout,"chrld uid = %u\n",getuid());
                    //getuid();
                }
            }
            exit(0);
        }
    }
  //  sleep(10);
    for(n = 0;n < FORK_N;n++)
        wait(NULL);

    //sleep(20);    
    printf("main.c end!\n");
    exit(0);
}




