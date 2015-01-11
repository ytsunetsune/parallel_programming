/* Q.親プロセスが2つの子プロセスを生成して，
 * それらの終了を待つプログラムを作成し，その動作を確認しなさい．
 * ただし，親プロセスは各子プロセスの終了をwait()で待つものとする．
 * ただし，wait()は1つの子プロセスの終了しか待たないので，
 * 2つの子プロセスの終了を待つときは，二度wait()を呼び出さなくてはならない．*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int status[2];
    pid_t pid1, pid2;

    if ((pid1 = fork()) == 0) {
        printf("pid1\n");
        sleep(2);
        exit(0);
    } else if ((pid2 = fork()) == 0){
        printf("pid2\n");
        sleep(2);
        exit(0);
    } else {
        for (int i = 0; i < 2; i++) {
            wait(&status[i]);
            printf("%d つ目返ってきたよ status = %x04\n", i + 1, status[i]);
        }
        printf("ぜんぶ返ってきたから終わるね\n");
    }

    return 0;
}
