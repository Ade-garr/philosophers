/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd_mstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:17:39 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/15 17:55:03 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_dif_timeval(struct timeval current, struct timeval last)
{
	unsigned int	dif;

	dif = (current.tv_sec - last.tv_sec) * 1000 + (current.tv_usec - last.tv_usec) / 1000;
	return (dif);
}

void	*ft_rout_mstr(void *arg)
{
	while (*((t_thrd *)arg)->setup != 1)
	{
		if (*((t_thrd *)arg)->setup == 2)
			return NULL;
	}
	while (1)
	{
		if (*((t_thrd *)arg)->end == 1)
			return NULL;
		gettimeofday(&((t_thrd *)arg)->current, NULL);
		if (ft_dif_timeval(((t_thrd *)arg)->current, *((t_thrd *)arg)->last) >= (unsigned int)((t_thrd *)arg)->ttd && *((t_thrd *)arg)->is_eating == 0)
		{
			*((t_thrd *)arg)->end = 1;
			ft_write_death((t_thrd *)arg);
			// close(1);
			return NULL;
		}
	}
}