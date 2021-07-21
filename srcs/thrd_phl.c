/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_phl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:44:30 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/21 21:31:03 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_rout_phl_last(void *arg)
{
	int	count;

	count = 0;
	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
		usleep(100);
	}
	if (((t_thrd *)arg)->id % 2 == 0)
		usleep(100);
	((t_thrd *)arg)->current = *((t_thrd *)arg)->init;
	while (*((t_thrd *)arg)->end != 1 && (count == 0 || count != ((t_thrd *)arg)->nb_tme))
	{
		ft_write_think((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[0]);
		ft_write_fork((t_thrd *)arg);
		gettimeofday(((t_thrd *)arg)->last, NULL);
		ft_write_eat((t_thrd *)arg);
		count++;
		ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tte);
		pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[0]);
		pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		ft_write_sleep((t_thrd *)arg);
		ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tts);
	}
	*((t_thrd *)arg)->end = 1;
	return NULL;
}


void	*ft_rout_phl(void *arg)
{
	int	count;

	count = 0;
	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
		usleep(100);
	}
	if (((t_thrd *)arg)->id % 2 == 0)
		usleep(100);
	((t_thrd *)arg)->current = *((t_thrd *)arg)->init;
	while (*((t_thrd *)arg)->end != 1 && (count == 0 || count != ((t_thrd *)arg)->nb_tme))
	{
		ft_write_think((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		ft_write_fork((t_thrd *)arg);
		*((t_thrd *)arg)->last = ((t_thrd *)arg)->current;
		ft_write_eat((t_thrd *)arg);
		count++;
		ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tte);
		pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		ft_write_sleep((t_thrd *)arg);
		ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tts);
	}
	*((t_thrd *)arg)->end = 1;
	return NULL;
}
