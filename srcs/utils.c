/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:59:07 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 19:38:44 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct2(t_philo *philo)
{
	int	i;

	if (philo->tab_mstr2 != 0)
	{
		pthread_join(philo->tab_mstr2, NULL);
		pthread_detach(philo->tab_mstr2);
	}
	if (philo->tab_mtx != NULL)
	{
		i = -1;
		while (++i < philo->nb_phl)
			pthread_mutex_destroy(&philo->tab_mtx[i]);
		free(philo->tab_mtx);
	}
	if (philo->tab_thrd != NULL)
	{
		i = 0;
		while (i < philo->nb_phl)
		{
			free(philo->tab_thrd[i].last);
			i++;
		}
		free(philo->tab_thrd);
	}
	free(philo);
}

void	free_struct(t_philo *philo)
{
	int	i;

	if (philo->tab_phl != NULL)
	{
		i = 0;
		while (i < philo->nb_phl)
		{
			if (philo->tab_phl[i] != 0)
			{
				pthread_join(philo->tab_phl[i], NULL);
				pthread_detach(philo->tab_phl[i]);
			}
			i++;
		}
		free(philo->tab_phl);
	}
	if (philo->tab_mstr1 != 0)
	{
		pthread_join(philo->tab_mstr1, NULL);
		pthread_detach(philo->tab_mstr1);
	}
	free_struct2(philo);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "Error : too few arguments\n", 26);
		return (1);
	}
	else if (argc > 6)
	{
		write(1, "Error : too many arguments\n", 27);
		return (1);
	}
	if (ft_check_num(argc, argv) == 1)
	{
		write(1, "Error : invalid argument\n", 25);
		return (1);
	}
	return (0);
}

void	ft_usleep(struct timeval *current, int time)
{
	struct timeval		start;
	unsigned long int	dif;

	start = *current;
	dif = (current->tv_sec * 1000 + current->tv_usec / 1000) - \
	(start.tv_sec * 1000 + start.tv_usec / 1000);
	while (dif < (unsigned int)time)
	{
		usleep(100);
		gettimeofday(current, NULL);
		dif = (current->tv_sec * 1000 + current->tv_usec / 1000) - \
		(start.tv_sec * 1000 + start.tv_usec / 1000);
	}
}

int	ft_check_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit((int)argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
