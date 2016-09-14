#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define QLEN    10

/*
 * Create a server endpoint of a connection.
 * Returns fd if all OK, <0 on error.
 */
int
serv_listen(const char *name)
{
    int                fd, len, err, rval;
    struct sockaddr_un un;

    if (strlen(name) >= sizeof(un.sun_path)) {
        errno = ENAMETOOLONG;
        return (-1);
    }

    /* create a UNIX domain stream socket */
    if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) <0) {
        return (-2);
    }

    unlink(name);   /* in case it already exists */

    /* fill in socket address structure */
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, name);

    /*
     * offsetof - offset of a structure member
     * #include <stddef.h>
     * size_t offsetof(type, member)
     *
     * The macro offsetof() returns the offset of the field member from the start of the structure type.
     * This macro is useful because the size of the fields that compose a structure can vary across implementations,
     * and compilers may insert different numbers of padding bytes between fields.
     * Consequently, an element's offset is not necessarily given by the sum of the sizes of the previous elements.
     *
     * A compiler error will result if member is not aligned to a byte boundary (ie. it is a bit field).
     *
     * offset() returns the offset of the given member within the given type, in units of bytes.
     */
    len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

    /* bind the name to the descriptor */
    if (bind(fd, (struct sockaddr *)&un, len) < 0) {
        rval = -3;
        goto errout;
    }

    if (listen(fd, QLEN) < 0) { /* tell kernel we are a server */
        rval = -4;
        goto errout;
    }
    return (fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return (rval);
}
