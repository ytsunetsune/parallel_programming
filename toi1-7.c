/* Q.親プロセスが子プロセスを生成し，
 * 子プロセスが孫プロセスを生成するプログラムを作成し，
 * その動作を確認しなさい．
 * ただし，親プロセスは子プロセスの終了を，子プロセスは孫プロセスの終了を，
 * それぞれwait()で待つものとする．*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int status1, status2;
    pid_t pid1, pid2;

    if ((pid1 = fork()) == 0) {
        if ((pid2 = fork()) == 0) {
            printf("孫です\n");
            sleep(2);
            exit(0);
        } else {
            printf("子です\n");
            wait(&status2);
            printf("孫が返ってきたよ status = %x04\n", status2);
            sleep(2);
            exit(0);
        }
    } else {
        printf("親です\n");
        wait(&status1);
        printf("子が返ってきたよ status = %x04\n", status1);
        printf("親「ぜんぶ返ってきたから終わるね」\n");
    }

    return 0;
}
