#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    fprintf(stdout,"打印测试信息 %d\n",10);
    fprintf(stderr,"打印测试信息 %d\n",10);

    char str[] = "1234";

    fprintf(stdout,"%d \n",atoi(str));

    exit(0);
}
