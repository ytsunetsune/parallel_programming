#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status;

    if (fork() == 0){
        printf("子のプロセスID = %d\n", getpid());
        sleep(2);
        exit(3);
    } else {
        wait(&status);
        printf("親のプロセスID = %d\n", getpid());
        printf("子プロセス終了時の値 = %04x\n", status);
    }
    exit(0);
}
