/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:08 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/13 14:47:31 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h> // A SUPPRIMER

typedef struct s_philo
{
	int	nb_phl;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_tme;
	pthread_t	*tab_phl;
	pthread_t	*tab_mstr;
	pthread_mutex_t	*tab_mtx;
	pthread_mutex_t	syscl;
	struct timeval	init;
	struct timeval	current;
	int	setup;
	int	death;
}	t_philo;

// FT_ATOI.C
int		ft_atoi(const char *nptr);

//	FT_CALLOC.C
void	*ft_calloc(size_t nmemb, size_t size);

//  FT_ISDIGIT.C
int		ft_isdigit(int c);

//  MAIN.C
t_philo	*init_philo(int argc, char **argv);
int		main(int argc, char **argv);

//  UTILS.C
int		ft_check_args(int argc, char **argv);
int		ft_check_num(int argc, char **argv);

#endif