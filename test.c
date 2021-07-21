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
// 	int	dif;

// 	i = gettimeofday(&tv, NULL);
// 	if (i == -1)
// 	{
// 		write(1, "Error : gettimeofday failed\n, ", 30);
// 		return (1);
// 	}
// 	// printf("tv_sec = %ld\n", tv.tv_sec);
// 	// printf("tv_usec = %ld\n", tv.tv_usec);
// 	usleep(2000000);
// 	i = gettimeofday(&tv2, NULL);
// 	// printf("tv_sec = %ld\n", tv2.tv_sec);
// 	// printf("tv_usec = %ld\n", tv2.tv_usec);
// 	// printf("dif = %ld\n", tv2.tv_sec - tv.tv_sec);
// 	// printf("dif = %ld\n", tv2.tv_usec - tv.tv_usec);
// 	// printf("dif tv_usec = %d\n", dif2);
// 	dif = (tv2.tv_sec - tv.tv_sec) * 1000 + (tv2.tv_usec - tv.tv_usec) / 1000;
// 	printf("dif = %d ms\n", dif);
// 	return (0);
// }



///////////////////////////////////////////////////////////////////////////
/////	THREADS
///////////////////////////////////////////////////////////////////////////

// void	*routine(void *arg)
// {
// 	(void)arg;
// 	usleep(9000000);
// 	return NULL;
// }

// int	main()
// {
// 	pthread_t	th;
//     int         ret;

//     th = 0;
// 	// pthread_create(&th, NULL, routine, NULL);
// 	ret = pthread_join(th, NULL);
//     printf("ret = %d\n", ret);
// 	pthread_detach(th);
// 	usleep(2000000);
// 	return (0);
// }



///////////////////////////////////////////////////////////////////////////
/////	USLEEP
///////////////////////////////////////////////////////////////////////////

// int	main()
// {
// 	unsigned long int	conv;

// 	conv = 300*1000;
// 	usleep(conv);
// 	write(1, "Done!\n", 6);
// 	return (0);
// }



///////////////////////////////////////////////////////////////////////////
/////	STRUCTS
///////////////////////////////////////////////////////////////////////////

// typedef struct s_test
// {
// 	int	a;
// }				t_test;

void	ft_test(struct timeval mdr)
{
	mdr.tv_usec = 88;
}

int	main()
{
	struct timeval	lol;
	struct timeval mdr;
	pthread_t test;

	gettimeofday(&lol, NULL);
	printf("lol.sec = %ld\n", lol.tv_sec);
	printf("lol.usec = %ld\n", lol.tv_usec);
	pthread_create(&test, NULL, ft_test, &mdr); // a voir si modif arg

	mdr = lol;
	ft_test(mdr);
	printf("mdr.sec = %ld\n", mdr.tv_sec);
	printf("mdr.sec = %ld\n", mdr.tv_usec);
	return (0);
}