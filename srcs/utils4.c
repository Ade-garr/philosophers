/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:46:25 by ade-garr          #+#    #+#             */
/*   Updated: 2021/08/23 16:51:52 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_done(t_thrd *arg)
{
	pthread_mutex_lock(&arg->mtx_done);
	if (arg->done == 1)
	{
		pthread_mutex_unlock(&arg->mtx_done);
		return (1);
	}
	pthread_mutex_unlock(&arg->mtx_done);
	return (0);
}

void	free_struct3(t_philo *philo)
{
	int	i;

	pthread_mutex_destroy(&philo->wrt);
	pthread_mutex_destroy(&philo->stop);
	if (philo->tab_thrd != NULL)
	{
		i = -1;
		while (++i < philo->nb_phl)
		{
			pthread_mutex_destroy(&philo->tab_thrd[i].mtx_last);
			pthread_mutex_destroy(&philo->tab_thrd[i].mtx_done);
			free(philo->tab_thrd[i].last);
		}
		free(philo->tab_thrd);
	}
	free(philo);
}
