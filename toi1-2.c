/* Q.fork()を次のように2回使用すると
 * どのような結果が得られるかを調べ，
 * その理由を述べなさい*/

/* A.3つのプロセスIDが表示される．
 * 1つ目に生成された子プロセスが2つ目の子プロセスを生成するため，
 * 親プロセス，子プロセス1，子プロセス2のIDが表示される．*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    fork();
    fork();
    printf("プロセスid = %d\n", getpid());
    return 0;
}
