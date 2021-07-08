/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:11:02 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/08 14:13:26 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;

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
		free(philo);
		return (NULL);
	}
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
	return (0);
}
