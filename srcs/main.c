/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:11:02 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 03:23:33 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	param_thrd(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_phl)
	{
		philo->tab_thrd[i].id = i + 1;
		philo->tab_thrd[i].nb_phl = philo->nb_phl;
		philo->tab_thrd[i].ttd = philo->ttd;
		philo->tab_thrd[i].tte = philo->tte;
		philo->tab_thrd[i].tts = philo->tts;
		philo->tab_thrd[i].nb_tme = philo->nb_tme;
		philo->tab_thrd[i].end = &philo->end;
		philo->tab_thrd[i].init = &philo->init;
		philo->tab_thrd[i].tab_mtx = philo->tab_mtx;
		i++;
	}
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
				pthread_create(&philo->tab_phl[i], NULL, ft_rout_phl_last, &philo->tab_thrd[i]); // a voir si modif arg
			else	
				pthread_create(&philo->tab_phl[i], NULL, ft_rout_phl, &philo->tab_thrd[i]); // a voir si modif arg
		}
		i++;
	}
	pthread_create(&philo->tab_mstr1, NULL, ft_rout_mstr_i, philo->tab_thrd); // a voir si modif arg
	usleep(1000);
	i = 0;
	while (i < philo->nb_phl)
	{
		if ((i + 1) % 2 == 0)
		{
			*philo->tab_thrd[i].last = philo->init;
			if (i == philo->nb_phl - 1)
				pthread_create(&philo->tab_phl[i], NULL, ft_rout_phl_last, &philo->tab_thrd[i]); // a voir si modif arg
			else	
				pthread_create(&philo->tab_phl[i], NULL, ft_rout_phl, &philo->tab_thrd[i]); // a voir si modif arg
		}
		i++;
	}
	pthread_create(&philo->tab_mstr2, NULL, ft_rout_mstr_p, philo->tab_thrd); // a voir si modif arg
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
	if (philo->tab_mstr2 != 0)
	{
		pthread_join(philo->tab_mstr2, NULL);
		pthread_detach(philo->tab_mstr2);
	}
	if (philo->tab_mtx != NULL)
	{
		i = 0;
		while (i < philo->nb_phl)
		{
			pthread_mutex_destroy(&philo->tab_mtx[i]);
			i++;
		}
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

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (philo == NULL)
	{
		write(1, "Error : malloc failed\n", 22);
		return (NULL);
	}
	philo->nb_phl = ft_atoi(argv[1]);
	philo->ttd = ft_atoi(argv[2]);
	philo->tte = ft_atoi(argv[3]);
	philo->tts = ft_atoi(argv[4]);
	if (argc == 6)
		philo->nb_tme = ft_atoi(argv[5]);
	if (philo->nb_phl < 0 || philo->ttd < 0 || philo->tte < 0
		|| philo->tts < 0 || philo->nb_tme < 0)
	{
		write(1, "Error : invalid argument\n", 25);
		free_struct(philo);
		return (NULL);
	}
	philo->tab_phl = (pthread_t *)ft_calloc(philo->nb_phl, sizeof(pthread_t));
	if (philo->tab_phl == NULL)
	{
		write(1, "Error : malloc failed\n", 22);
		free_struct(philo);
		return (NULL);
	}
	philo->tab_mtx = (pthread_mutex_t *)ft_calloc(philo->nb_phl, sizeof(pthread_mutex_t));
	if (philo->tab_mtx == NULL)
	{
		write(1, "Error : malloc failed\n", 22);
		free_struct(philo);
		return (NULL);
	}
	philo->tab_thrd = (t_thrd *)ft_calloc(philo->nb_phl, sizeof(t_thrd));
	if (philo->tab_thrd == NULL)
	{
		write(1, "Error : malloc failed\n", 22);
		free_struct(philo);
		return (NULL);
	}
	i = 0;
	while (i < philo->nb_phl)
	{
		philo->tab_thrd[i].last = ft_calloc(1, sizeof(struct timeval));
		if (philo->tab_thrd[i].last == NULL)
		{
			write(1, "Error : malloc failed\n", 22);
			free_struct(philo);
			return (NULL);
		}
		i++;
	}
	i = 0;
	while (i < philo->nb_phl)
	{
		pthread_mutex_init(&philo->tab_mtx[i], NULL);
		i++;
	}
	param_thrd(philo);
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (ft_check_args(argc, argv) == 1)
		return (1);
	philo = init_philo(argc, argv);
	if (philo == NULL)
		return (1);
	init_threads(philo);
	free_struct(philo);
	return (0);
}
