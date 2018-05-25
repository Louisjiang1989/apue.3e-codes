#include "apue.h"
#include <sys/wait.h>

/* 
 * 子进程的结束状态返回后存于status，底下有几个宏可判别结束情况  
 * WIFEXITED(status):        如果子进程正常结束则为非0值。  
 * WEXITSTATUS(status):      取得子进程exit()返回的结束代码，一般会先用WIFEXITED 来判断是否正常结束才能使用此宏。  
 * WIFSIGNALED(status):      如果子进程是因为信号而结束则此宏值为真 
 * WTERMSIG(status):         取得子进程因信号而中止的信号代码，一般会先用WIFSIGNALED 来判断后才使用此宏。  
 * WIFSTOPPED(status):       如果子进程处于暂停执行情况则此宏值为真。一般只有使用WUNTRACED 时才会有此情况。  
 * WSTOPSIG(status):         取得引发子进程暂停的信号代码，一般会先用WIFSTOPPED 来判断后才使用此宏。
 */

void
pr_exit(int status) 
{
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
                WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n",
                WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status) ? " (core file generated)" : "");
#else 
                "");
#endif
    } 
    else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}
