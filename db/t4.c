#include "apue.h"
#include "apue_db.h"
#include <fcntl.h>

int 
main(void)
{
    char teststr[8];

    sprintf(teststr, "%*d", 7, 0);

    printf("teststr: %s\n", teststr);

    DBHANDLE db;

    if ((db = db_open("db4", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) == NULL)
        err_sys("db_open error");

    print_db(db);    

    if (db_store(db, "Alpha", "data1", DB_INSERT) != 0)
        err_quit("db_store error for alpha");

    print_db(db);    

    if (db_store(db, "beta", "Data for beta", DB_INSERT) != 0)
        err_quit("db_store error for beta");
    
    print_db(db);

    if (db_store(db, "gamma", "record3", DB_INSERT) != 0)
        err_quit("db_store error for gamma");

    print_db(db);

    /*char *value = db_fetch(db, "Alpha");
    printf("Alpha: %s\n", value);

    value = db_fetch(db, "Baaaa");
    printf("Baaaa: %s\n", value);

    if (db_store(db, "Alpha", "newe1dadafas", DB_REPLACE) != 0)
	err_quit("db_store replica error newe1");*/

    db_close(db);
    exit(0);
}
