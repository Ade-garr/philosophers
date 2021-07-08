/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:08 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/08 14:13:30 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h" // A SUPPRIMER

typedef struct s_philo
{
	int	nb_phl;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_tme;
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