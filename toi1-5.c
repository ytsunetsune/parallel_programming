/* Q.親プロセスがwait(&status)で子プロセスの終了を待つプログラム例で，
 * 子プロセスがexit()を使わないとき，wait()の引数である変数statusには
 * どのような値が返されるか調べなさい．
 * また，その結果はLinuxではどのような意味を持つかについても調べなさい．*/

/* A.0が返ってくる．
 * 0はLinuxでは大抵の場合，正常終了を意味する．
 * (必ずそうとは限らない)*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int status;

    if (fork() == 0) {
        printf("子プロセスなう\n");
        sleep(2);
    } else {
        printf("子プロセス待ってるなう\n");
        wait(&status);
        printf("status = %d\n", status);
    }
    exit(0);
}
