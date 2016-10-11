#include "apue.h"
#include <fcntl.h>

int 
main(int argc, char *argv[])
{
    if (argc != 2)
        err_quit("usage: a.out <pathname>");
    /*
     * access, faccessat --- check user's permissions for a file
     *
     * #include <unistd.h>
     * int access(const char *pathname, int mode);
     *
     * access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, 
     * it is dereferenced.
     *
     * #include <fcntl.h>
     * #include <unistd.h>
     * int faccessat(int dirfd, const char *pathname, int mode, int flags);
     *
     * faccessat() system call operates in exactly the same way as access(), except for the difference described here.
     *
     * If the pathname given in pathname is relative, then it is interpreted relative to the directory referred to 
     * by the file descriptor dirfd (rather than relative to the current working directory of the calling process, as is 
     * done by access() for a relative pathname).
     *
     * If pathname is relative and dirfd is the special value AI_FDCWD, then pathname is interpreted relative to the 
     * current working directory of the calling process (like access()).
     *
     * If pathname is absoute, then dirfd is ignored.
     *
     * flags is constructed by ORing together zero or more of the following values.
     *
     * On success (all requested permissions granted, or mode is F_OK and the file exists), zero is returned.
     * On error (at least one bit in mode asked for a permission that is denied, or mode is F_OK and the file does not 
     * exist, or some other error occurred), -1 is returned, and errno is set appropriately.
     */
    if (access(argv[1], R_OK) < 0)
        err_ret("access error for %s", argv[1]);
    else
        printf("read access OK\n");

    if (open(argv[1], O_RDONLY) < 0)
        err_ret("open error for %s", argv[1]);
    else
        printf("open for reading OK\n");

    exit(0);
}
