/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:25:29 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/19 12:50:04 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simul(t_philo *philo)
{
	int ret;
	int	i;

	ret = gettimeofday(&philo->init, NULL);
	if (ret == -1)
	{
		write(1, "Error : gettimeofday failed\n", 28);
		philo->setup = 2;
		free_struct(philo);
		return (1);
	}
	i = 0;
	while (i < philo->nb_phl)
	{
		*philo->tab_thrd[i].last = philo->init;
		i++;
	}
	write(1, "Simulation start !\n", 19);
	philo->setup = 1;
	return (0);
}
