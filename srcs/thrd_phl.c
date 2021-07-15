/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_phl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:44:30 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/15 04:55:16 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_rout_phl(void *arg)
{
	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
	}
	((t_thrd *)arg)->last = *((t_thrd *)arg)->init;
	while (1)
	{
		if (*((t_thrd *)arg)->death == 1)
			return (0);
		ft_write_think((t_thrd *)arg);
		if (((t_thrd *)arg)->id == ((t_thrd *)arg)->nb_phl)
		{
			pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[0]);
			ft_write_fork((t_thrd *)arg);
			pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
			ft_write_fork((t_thrd *)arg);
		}
		else
		{
			pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
			ft_write_fork((t_thrd *)arg);
			pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
			ft_write_fork((t_thrd *)arg);
		}
		ft_write_eat((t_thrd *)arg);
		usleep(ft_conv_ms(((t_thrd *)arg)->tte));
		if (((t_thrd *)arg)->id == ((t_thrd *)arg)->nb_phl)
		{
			pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[0]);
			pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		}
		else
		{
			pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
			pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		}
		ft_write_sleep((t_thrd *)arg);
		usleep(ft_conv_ms(((t_thrd *)arg)->tts));
	}
}
