#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


///////////////////////////////////////////////////////////////////////////
/////	TIME OF DAY
///////////////////////////////////////////////////////////////////////////

// int main()
// {
// 	struct timeval	tv;
// 	struct timeval	tv2;
// 	int	i;
// 	i = gettimeofday(&tv, NULL);
// 	if (i == -1)
// 	{
// 		write(1, "Error : gettimeofday failed\n, ", 30);
// 		return (1);
// 	}
// 	printf("tv_sec = %ld\n", tv.tv_sec);
// 	printf("tv_usec = %ld\n", tv.tv_usec);
// 	usleep(2000000);
// 	i = gettimeofday(&tv2, NULL);
// 	printf("tv_sec = %ld\n", tv2.tv_sec);
// 	printf("tv_usec = %ld\n", tv2.tv_usec);
// 	printf("dif = %ld\n", tv2.tv_sec - tv.tv_sec);
// 	printf("dif = %ld\n", tv2.tv_usec - tv.tv_usec);
// 	// printf("dif tv_usec = %d\n", dif2);
// 	return (0);
// }



///////////////////////////////////////////////////////////////////////////
/////	THREADS
///////////////////////////////////////////////////////////////////////////

void	*routine(void *arg)
{
	(void)arg;
	usleep(9000000);
	return NULL;
}

int	main()
{
	pthread_t	th;

	pthread_create(&th, NULL, routine, NULL);
	pthread_join(th, NULL);
	pthread_detach(th);
	usleep(2000000);
	return (0);
}