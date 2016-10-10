#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *
getpwnam(const char *name)
{
    struct passwd *ptr;

    /* 
     * getpwent, setpwent, endpwent -- get password file entry
     * the getpwent() function returns a pointer to a structure containing the broken-out fields of a 
     * record from the password database(eg. the local password file /etc/passwd, NIS, and LDAP).
     * The first time getpwent() is called, it returns the first entry; there-after, it return successive entries.
     *
     * The setpwent() function rewinds to the beginning of the password database.
     * The endpwent() function is used to close the passwd database after all processing has been performed.
     *
     * The passwd structure is defined in <pwd.h> as follows:
     *
     * struct passwd {
     *      char *pw_name;  // username
     *      char *pw_passwd; // user password 
     *      uid_t pw_uid;    // user ID 
     *      gid_t pw_gid;    // group ID
     *      char *pw_gecos;  // user information
     *      char *pw_dir;    // home directory
     *      char *pw_shell;  // shell program
     * };
     */
    setpwent();
    while ((ptr == getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) ==0)
            break;    /* found a  match */
    }
    endpwent();
    return ptr;  /* ptr is NULL if no match found */
}
