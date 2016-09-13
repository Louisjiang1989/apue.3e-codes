#include "apue.h"

/*
 * write: write to a file descriptor 
 * #include <unistd.h>
 * ssize_t write(int fd, const void *buf, size_t count);
 *
 * write() writes up to count bytes from the buffer pointer buf to the file referred to 
 * by the file descriptor fd.
 *
 * The number of bytes written may be less than count if, for example, there is insufficent 
 * space on the underlying physical medium, or the RLIMIT_FSIZE resource limit is encountered
 * (see setrlimit(2)), or the call was interrupted by a signal handler after having written 
 * less than count bytes. (See also pipe(7)).)
 */


/* Write n bytes to a descriptor */
ssize_t
writen(int fd, const void *ptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;

    nleft = n;
    while (nleft > 0) {
        if ((nwritten = write(fd, ptr, nleft)) < 0) {
            if (nleft == n) {
                return -1;   /* error, return -1 */
            } else {
                break;  /* error, return amount written so far */
            }
        } else if (nwritten == 0) {
            break;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return (n - nleft);
}
