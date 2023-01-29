#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
fopen(); 
创建的新文件的权限计算公式： (0666 & ～umask) 
其中 umask 等于 0002
*/


int main(int argc,char *argv[])
{
    FILE *fp;
    int cnt = 0;
    
    // while(1){

    //     fp = fopen("test.c","r");
    //     if(fp == NULL){
    //         //两种打印错误信息的函数,strerror(),perror()
    //         fprintf(stderr,"fopen error,errno = %s\n",strerror(errno));
    //         //perror("fopen error: ");
    //         break;
    //     }
    //     cnt++;
    // }EOF

    
     printf("cnt = %d\n",EOF);
     //fclose(fp);
     exit(0);
 }
             