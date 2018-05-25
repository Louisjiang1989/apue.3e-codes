#include <stdio.h>

FILE *
open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZ]; /*setvbuf makes this the stdio buffer */

    /* 
     * fopen, fdopen, freopen -- stream open functions
     * The fopen() function opens the file whose name is the string pointed by path and associates a stream with it.
     * The fdopen() function associates a stream with the exiting file descriptor, fd. The mode of the stream (one of the 
     * values "r", "r+", "w", "w+", "a", "a+") must be compatible with the mode of the file descriptor.
     * The freopen() function opens the file whose name is the string pointed to by path and assocaites the stream pointed
     * to by stream with it. The original stream (if it exits) is closed. The mode argument is used just as in the fopen()
     * function. The primary use of the freopen() function is to change the file assiciated with a standard text stream 
     * (stderr, stdin, or stdout).
     */
    if ((fp = fopen("datafile", "r")) == NULL)
        return NULL;

    /* 
     * setbuf, setbuffer, setlinebuf, setvbuf -- stream buffering operations
     * The setvbuf() function may be used on any open stream to change its buffer, The mode argument must be one of the 
     * following three macros:
     *  _IONBF unbufferd
     *  _IOLBF line buffered
     *  _IO_FBF fully buffered
     */
    if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return NULL;
    return fp;
}
