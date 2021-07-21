/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:17:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/21 13:55:20 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

float	ft_dif_timeval(struct timeval current, struct timeval last)
{
	float	dif;

	dif = (current.tv_sec - last.tv_sec) * 1000 + (current.tv_usec - last.tv_usec) / 1000;
	return (dif);
}

void	*ft_rout_mstr(void *arg)
{
	struct timeval	last;

	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
	}
	while (1)
	{
		if (*((t_thrd *)arg)->end == 1)
			return NULL;
		last = *((t_thrd *)arg)->last;
		gettimeofday(&((t_thrd *)arg)->current_mstr, NULL);
		if (ft_dif_timeval(((t_thrd *)arg)->current_mstr, last) >= ((t_thrd *)arg)->ttd)
		{
			pthread_mutex_lock(((t_thrd *)arg)->syscl);
			printf("dif = %f\n", ft_dif_timeval(((t_thrd *)arg)->current_mstr, last));
			pthread_mutex_unlock(((t_thrd *)arg)->syscl);
			*((t_thrd *)arg)->end = 1;
			ft_write_death((t_thrd *)arg);
			return NULL;
		}
	}
}