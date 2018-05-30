#include "../include/apue.h"

int 
main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf("%s\n", tmpnam(NULL));               //first temp name 

    tmpnam(name);                              //second temp name
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL)               // create temp file
        err_sys("tmpfile error");

    fputs("one line of output\n", fp);           // write to temp file
    rewind(fp);                                 // move the fp pos pointer tp the SEEK_SET
    if (fgets(line, sizeof(line), fp) == NULL)  // then read it back
        err_sys("fgets error");                
    fputs(line, stdout);                       // print the line we wrote

    exit(0);
}
