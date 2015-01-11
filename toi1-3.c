/* Q.fork()を呼び出して子プロセスを作り，
 * 子プロセスにのみ「こんにちは」と
 * メッセージを表示させるプログラムを作りなさい*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    if (fork() == 0) {
        printf("こんにちは\n");
    }
    return 0;
}
