/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_phl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:44:29 by ade-garr          #+#    #+#             */
/*   Updated: 2021/08/23 16:45:13 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_rout_phl(void *arg)
{
	int	count;

	count = 0;
	while (ft_check_end((t_thrd *)arg) != 1)
	{
		if (count != 0 && count == ((t_thrd *)arg)->nb_tme)
		{
			pthread_mutex_lock(&((t_thrd *)arg)->mtx_done);
			((t_thrd *)arg)->done = 1;
			pthread_mutex_unlock(&((t_thrd *)arg)->mtx_done);
			return (NULL);
		}
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->mtx_last);
		*((t_thrd *)arg)->last = ((t_thrd *)arg)->current;
		pthread_mutex_unlock(&((t_thrd *)arg)->mtx_last);
		ft_write_eat((t_thrd *)arg);
		count++;
		ft_rout_phl2(arg);
	}
	return (NULL);
}

void	ft_rout_phl2_i(void *arg)
{
	ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tte);
	pthread_mutex_unlock(&((t_thrd *)arg)->\
	tab_mtx[((t_thrd *)arg)->id - 1]);
	pthread_mutex_unlock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
	ft_write_sleep((t_thrd *)arg);
	ft_usleep(&((t_thrd *)arg)->current, ((t_thrd *)arg)->tts);
	ft_write_think((t_thrd *)arg);
}

void	*ft_rout_phl_i(void *arg)
{
	int	count;

	count = 0;
	while (ft_check_end((t_thrd *)arg) != 1)
	{
		if (count != 0 && count == ((t_thrd *)arg)->nb_tme)
		{
			pthread_mutex_lock(&((t_thrd *)arg)->mtx_done);
			((t_thrd *)arg)->done = 1;
			pthread_mutex_unlock(&((t_thrd *)arg)->mtx_done);
			return (NULL);
		}
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id - 1]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->tab_mtx[((t_thrd *)arg)->id]);
		ft_write_fork((t_thrd *)arg);
		pthread_mutex_lock(&((t_thrd *)arg)->mtx_last);
		*((t_thrd *)arg)->last = ((t_thrd *)arg)->current;
		pthread_mutex_unlock(&((t_thrd *)arg)->mtx_last);
		ft_write_eat((t_thrd *)arg);
		count++;
		ft_rout_phl2_i(arg);
	}
	return (NULL);
}
