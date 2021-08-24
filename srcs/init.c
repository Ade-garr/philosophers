/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:56:01 by ade-garr          #+#    #+#             */
/*   Updated: 2021/08/24 14:44:03 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads2(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_phl)
	{
		if ((i + 1) % 2 == 0)
		{
			*philo->tab_thrd[i].last = philo->init;
			if (i == philo->nb_phl - 1)
				pthread_create(&philo->tab_phl[i], NULL, \
				ft_rout_phl_last_i, &philo->tab_thrd[i]);
			else
				pthread_create(&philo->tab_phl[i], NULL, \
				ft_rout_phl_i, &philo->tab_thrd[i]);
		}
		i++;
	}
	if (philo->nb_phl != 1)
		pthread_create(&philo->tab_mstr2, NULL, \
		ft_rout_mstr_p, philo->tab_thrd);
}

void	init_threads(t_philo *philo)
{
	int	i;

	write(1, "Simulation start !\n", 19);
	gettimeofday(&philo->init, NULL);
	i = 0;
	while (i < philo->nb_phl)
	{
		if ((i + 1) % 2 == 1)
		{
			*philo->tab_thrd[i].last = philo->init;
			if (i == philo->nb_phl - 1)
				pthread_create(&philo->tab_phl[i], NULL, \
				ft_rout_phl_last_i, &philo->tab_thrd[i]);
			else
				pthread_create(&philo->tab_phl[i], NULL, \
				ft_rout_phl_i, &philo->tab_thrd[i]);
		}
		i++;
	}
	pthread_create(&philo->tab_mstr1, NULL, ft_rout_mstr_i, philo->tab_thrd);
	usleep(1000);
	init_threads2(philo);
}
