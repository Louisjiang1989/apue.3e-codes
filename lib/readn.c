#include "apue.h"

/*
 * read: read from a file descriptor
 *
 * #include <unistd.h>
 * ssize_t read(int fd, void *buf, size_t count);
 *
 * read() attempts to read up to count bytes from file descriptor fd into the buff starting at buf.
 *
 * On files that support seeking, the read operation commences at the current file offset, and the file 
 * offset is incremented by the number of bytes read. If the current file offset is at or past the end of
 * file, no bytes are read, and read() returns zero.
 * If count is zero, read() may detect the errors described below. In the absence of any errors, or if 
 * read() does not check for errors, a read() with a count of 0 returns zero and has no other effects.
 *
 * If count is greater than SSIZE_MAX, the result is unspecified.
 *
 * RETURN VALUE
 *
 * On sucess, the number of bytes read is returned (zero indicates end of file), and the file position
 * is advanced by this number. It is not an error if this number is smaller than of bytes requested;
 * this may happen for example because fewer bytes are actually avaiable right now (maybe because we 
 * were close to end-of-file, or because we are reading from a pipe, or from a terminal), or because
 * read() was interrupted by a signal. 
 *
 * On error, -1 is returned, and errno is set appropriately. In this case, it is left unspecified whether
 * the file position (if any) changes.
 */


/* Read n bytes from a descriptor */
ssize_t 
readn(int fd, void *ptr, size_t n) {
    size_t nleft;
    ssize_t nread;

    nleft = n;
    while(nleft > 0) {
        if ((nread = read(fd, ptr, nleft)) < 0) {
            if (nleft == n) {
                return -1;   /* error, return -1 */
            } else {
                break;   /* error, return amount read so far */
            }
        } else if (nread == 0) {
            break;   /* EOF */
        }
        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft);
}
