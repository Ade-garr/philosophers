/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:17:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 04:06:04 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long int	ft_dif_timeval(struct timeval current, struct timeval last)
{
	unsigned long int	dif;

	dif = (current.tv_sec * 1000 + current.tv_usec / 1000) - (last.tv_sec * 1000 + last.tv_usec / 1000);
	return (dif);
}

void	*ft_rout_mstr_i(void *arg)
{
	struct timeval	last;
	int	i;

	while (1)
	{
		i = 0;
		while (i < ((t_thrd *)arg)[0].nb_phl)
		{
			if ((i + 1) % 2 == 1)
			{
				if (*((t_thrd *)arg)[i].end == 1)
					return NULL;
				last = *((t_thrd *)arg)[i].last;
				gettimeofday(&((t_thrd *)arg)[i].current_mstr, NULL);
				if (ft_dif_timeval(((t_thrd *)arg)[i].current_mstr, last) > (unsigned long int)((t_thrd *)arg)[i].ttd)
				{
					if (*((t_thrd *)arg)[i].end == 0)
					{
						*((t_thrd *)arg)[i].end = 1;
						ft_write_death(&((t_thrd *)arg)[i]);
					}
					return NULL;
				}
			}
			i++;
		}
	}
}

void	*ft_rout_mstr_p(void *arg)
{
	struct timeval	last;
	int	i;

	while (1)
	{
		i = 0;
		while (i < ((t_thrd *)arg)[0].nb_phl)
		{
			if ((i + 1) % 2 == 0)
			{
				if (*((t_thrd *)arg)[i].end == 1)
					return NULL;
				last = *((t_thrd *)arg)[i].last;
				gettimeofday(&((t_thrd *)arg)[i].current_mstr, NULL);
				if (ft_dif_timeval(((t_thrd *)arg)[i].current_mstr, last) > (unsigned long int)((t_thrd *)arg)[i].ttd)
				{
					if (*((t_thrd *)arg)[i].end == 0)
					{
						*((t_thrd *)arg)[i].end = 1;
						ft_write_death(&((t_thrd *)arg)[i]);
					}
					return NULL;
				}
			}
			i++;
		}
	}
}
