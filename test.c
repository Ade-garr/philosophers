#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct timeval  *tv;
    struct timeval  *tv2;
    int i;
    int dif;
    int dif2;
    i = gettimeofday(tv, NULL);
    if (i == -1)
    {
        write(1, "Error : gettimeofday failed\n, ", 30);
        return (1);
    }
    printf("tv_sec = %ld\n", tv->tv_sec);
    printf("tv_usec = %d\n", tv->tv_usec);
    i = gettimeofday(tv2, NULL);
    dif = (int)tv->tv_sec - (int)tv2->tv_sec;
    // dif2 = (int)tv->tv_usec - (int)tv2->tv_usec;
    // printf("dif tv_sec = %d\n", dif);
    // printf("dif tv_usec = %d\n", dif2);
    return (0);
}