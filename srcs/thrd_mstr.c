/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:17:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/08/19 17:21:33 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	ft_dif_timeval(struct timeval current, struct timeval last)
{
	unsigned long int	dif;

	dif = (current.tv_sec * 1000 + current.tv_usec / 1000) - \
	(last.tv_sec * 1000 + last.tv_usec / 1000);
	return (dif);
}

int	check_finish(void *arg, int count)
{
	if (((t_thrd *)arg)[0].nb_phl % 2 == 0 && \
	count == ((t_thrd *)arg)[0].nb_phl / 2)
		return (1);
	if (((t_thrd *)arg)[0].nb_phl % 2 == 1 && \
	count == ((t_thrd *)arg)[0].nb_phl / 2 + 1)
		return (1);
	return (0);
}

int	check_time(void *arg, int i)
{
	struct timeval	last;

	pthread_mutex_lock(&((t_thrd *)arg)[i].mtx_last);
	last = *((t_thrd *)arg)[i].last;
	pthread_mutex_unlock(&((t_thrd *)arg)[i].mtx_last);
	gettimeofday(&((t_thrd *)arg)[i].current_mstr, NULL);
	if (ft_dif_timeval(((t_thrd *)arg)[i].current_mstr, last) > \
	(unsigned long int)((t_thrd *)arg)[i].ttd)
	{
		if (ft_check_end(&((t_thrd *)arg)[i]) == 0)
		{
			pthread_mutex_lock(((t_thrd *)arg)[i].stop);
			*((t_thrd *)arg)[i].end = 1;
			pthread_mutex_unlock(((t_thrd *)arg)[i].stop);
			ft_write_death(&((t_thrd *)arg)[i]);
		}
		return (1);
	}
	return (0);
}

void	*ft_rout_mstr_i(void *arg)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < ((t_thrd *)arg)[0].nb_phl)
		{
			if (ft_check_end(&((t_thrd *)arg)[i]) == 1)
				return (NULL);
			if (ft_check_done(&((t_thrd *)arg)[i]) == 1)
			{
				count++;
				if (check_finish(arg, count) == 1)
					return (NULL);
			}
			else
			{
				if (check_time(arg, i) == 1)
					return (NULL);
			}
			i = i + 2;
		}
	}
}

void	*ft_rout_mstr_p(void *arg)
{
	int				i;
	int				count;

	while (1)
	{
		i = 1;
		count = 0;
		while (i < ((t_thrd *)arg)[0].nb_phl)
		{
			if (ft_check_end(&((t_thrd *)arg)[i]) == 1)
				return (NULL);
			if (ft_check_done(&((t_thrd *)arg)[i]) == 1)
			{
				count++;
				if (count == ((t_thrd *)arg)[i].nb_phl / 2)
					return (NULL);
			}
			else
			{
				if (check_time(arg, i) == 1)
					return (NULL);
			}
			i = i + 2;
		}
	}
}
