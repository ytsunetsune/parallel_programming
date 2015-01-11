/* Q.fork()を呼び出して子プロセスを作り，
 * 親プロセスにのみ「ご機嫌いかがですか」と
 * メッセージを表示させるプログラムを作りなさい*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    if (fork() != 0) {
        printf("ご機嫌いかがですか\n");
    }
    return 0;
}
