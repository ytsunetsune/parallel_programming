/* Q.fork()の位置を次のように変更すると，
 * どのような実行結果が得られるかを調べ，
 * その理由を述べなさい*/

/* A.親プロセスのIDのみ表示される．
 * 子プロセスの開始位置がfork()からであるため．*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("プロセスid = %d\n", getpid());
    fork();
    return 0;
}
