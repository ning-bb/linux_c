#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void myint_handl(int n)
{
    write(1,"!",1);
}


int main(void)
{
    int i;
    signal(SIGINT,myint_handl);
    for(i = 0;i<10;i++){
        write(1,"*",1);
        sleep(1);
    }
    write(1,"\n",1);
    exit(0);
}