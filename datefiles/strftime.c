#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 
main(void)
{
    time_t t;
    struct tm *tmp;
    char buf1[16];
    char buf2[64];
    /*
     * time_t time(time_t *tloc)
     * time() returns the time as the number of seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC)
     * On success, the value of time in seconds since the Epoch is returned. On error, (time_t)-1 is returned,
     * and errno is set appropriately.
     */
    time(&t);
    /*
     * struct tm *localtime(const time_t *timep);
     * localtime() function take an argument of data type time_t, which represents calendar time.
     * The broken-down time is stored in the structure tm, which is defined in <time.h> as follows:
     * struct tm {
     *      int tm_sec;  // Seconds (0-60)
     *      int tm_min;  // Minutes (0-59)
     *      int tm_hour; // Hours (0-23)
     *      int tm_mday; // Day of the month (1-31)
     *      int tm_mon;  // Month (0-11)
     *      int tm_year; // Year - 1900
     *      int tm_wday; // Day of the week (0-6, Sunday = 0)
     *      int tm_yday; // Day of the year (0-365, 1 Jan = 0)
     *      int tm_isdst; // Daylight saving time 夏令时间
     * };
     */
    tmp = localtime(&t);
    /*
     * strftime -- format data and time
     * size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
     * The strftime() function formats the broken-down time tm according to the format specification format
     * and places the result in the character array s of size max.
     */
    if (strftime(buf1, 16, "time and data: %a %b %d, %Y", tmp) == 0)
        printf("buffer length 16 is too small\n");
    else 
        printf("%s\n", buf1);

    if (strftime(buf2, 64, "time and data: %a %b %d, %Y", tmp) == 0)
        printf("buffer length 64 is too small\n");
    else 
        printf("%s\n", buf2);
    
    exit(0);
}
