/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:17:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/20 01:26:14 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	ft_dif_timeval(struct timeval current, struct timeval last)
{
	float	dif;

	// dif = (current.tv_sec - last.tv_sec) * 1000 + (current.tv_usec - last.tv_usec) / 1000;
	dif = (current.tv_sec * 1000 + current.tv_usec / 1000 ) - (last.tv_sec * 1000 + last.tv_usec / 1000); 
	return (dif);
}

void	*ft_rout_mstr(void *arg)
{
	float	dif;
	unsigned int	last;
	unsigned int	current;
	// unsigned int	ts;



	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
	}
	while (1)
	{
		// usleep(1);
		if (*((t_thrd *)arg)->end == 1)
			return NULL;
		gettimeofday(&((t_thrd *)arg)->current, NULL);
		current = (((t_thrd *)arg)->current.tv_sec - ((t_thrd *)arg)->init->tv_sec) * 1000 + (((t_thrd *)arg)->current.tv_usec - ((t_thrd *)arg)->init->tv_usec) / 1000;
		last = (((t_thrd *)arg)->last->tv_sec - ((t_thrd *)arg)->init->tv_sec) * 1000 + (((t_thrd *)arg)->last->tv_usec - ((t_thrd *)arg)->init->tv_usec) / 1000;
		dif = current - last;
		// dif = ft_dif_timeval(((t_thrd *)arg)->current, *((t_thrd *)arg)->last);
		if (dif >= ((t_thrd *)arg)->ttd)
		{
			pthread_mutex_lock(((t_thrd *)arg)->syscl);
			printf("current = ");
			// ts = (((t_thrd *)arg)->current.tv_sec - ((t_thrd *)arg)->init->tv_sec) * 1000 + (((t_thrd *)arg)->current.tv_usec - ((t_thrd *)arg)->init->tv_usec) / 1000;
			write(1, "[", 1);
			ft_putnbr_fd(current, 1);
			write(1, " ms]", 4);
			printf("\nlast = ");
			// ts = (((t_thrd *)arg)->last->tv_sec - ((t_thrd *)arg)->init->tv_sec) * 1000 + (((t_thrd *)arg)->last->tv_usec - ((t_thrd *)arg)->init->tv_usec) / 1000;
			write(1, "[", 1);
			ft_putnbr_fd(last, 1);
			write(1, " ms]", 4);
			printf("\n");
			// printf("current = %ld\n", ((t_thrd *)arg)->current.tv_sec * 1000 + ((t_thrd *)arg)->current.tv_usec / 1000);
			// printf("last = %ld\n", ((t_thrd *)arg)->last->tv_sec * 1000 + ((t_thrd *)arg)->last->tv_usec / 1000);
			// printf("dif reel = %ld\n", (((t_thrd *)arg)->current.tv_sec * 1000 + ((t_thrd *)arg)->current.tv_usec / 1000) - (((t_thrd *)arg)->last->tv_sec * 1000 + ((t_thrd *)arg)->last->tv_usec / 1000));
			printf("dif = %f\n", dif);
			pthread_mutex_unlock(((t_thrd *)arg)->syscl);
			*((t_thrd *)arg)->end = 1;
			ft_write_death((t_thrd *)arg);
			return NULL;
		}
	}
}