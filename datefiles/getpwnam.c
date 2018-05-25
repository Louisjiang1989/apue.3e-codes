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
    while ((ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) ==0)
            break;    /* found a  match */
    }
    endpwent();
    return ptr;  /* ptr is NULL if no match found */
}

/*int main()
{
	struct passwd *pwd = getpwnam("root");
	if(pwd == NULL){
		printf("main passwd is NULL\n");
		exit(-1);
	}

	printf("pw_name: %s\n", pwd->pw_name);
	printf("pw_passwd: %s\n", pwd->pw_passwd);
	printf("pw_uid: %d\n", pwd->pw_uid);
	printf("pw_gid: %d\n", pwd->pw_gid);
	printf("pw_gecos: %s\n", pwd->pw_gecos);
	printf("pw_dir: %s\n", pwd->pw_dir);
	printf("pw_shell: %s\n", pwd->pw_shell);
	
	return 0;
}*/
