/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:08 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 04:02:31 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h> // A SUPPRIMER

typedef struct	s_thrd
{
	int	id;
	int	nb_phl;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_tme;
	int	*end;
	struct timeval	*init;
	struct timeval	current;
	struct timeval	current_mstr;
	pthread_mutex_t	*tab_mtx;
	struct timeval	*last;
}				t_thrd;

typedef struct s_philo
{
	int	nb_phl;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_tme;
	pthread_t	*tab_phl;
	pthread_t	tab_mstr1;
	pthread_t	tab_mstr2;
	pthread_mutex_t	*tab_mtx;
	t_thrd	*tab_thrd;
	struct timeval	init;
	int	end;
}	t_philo;

// FT_ATOI.C
int		ft_atoi(const char *nptr);

//	FT_CALLOC.C
void	*ft_calloc(size_t nmemb, size_t size);

//  FT_ISDIGIT.C
int		ft_isdigit(int c);

//  FT_PUTNBR_FD.C
void	ft_putnbr_fd(int n, int fd);

//  MAIN.C
void	param_thrd(t_philo *philo);
void		init_threads(t_philo *philo);
void	free_struct(t_philo *philo);
t_philo	*init_philo(int argc, char **argv);
int		main(int argc, char **argv);

//  THRD_PHL.C
void	*ft_rout_phl_last(void *arg);
void	*ft_rout_phl(void *arg);

//  THRD_MSTR.C
unsigned long int	ft_dif_timeval(struct timeval current, struct timeval last);
void	*ft_rout_mstr_i(void *arg);
void	*ft_rout_mstr_p(void *arg);

//  UTILS.C
void	ft_write_think(t_thrd *arg);
void	ft_write_eat(t_thrd *arg);
void	ft_write_sleep(t_thrd *arg);
void	ft_write_fork(t_thrd *arg);
void	ft_write_death(t_thrd *arg);
int	ft_write_ts_death(t_thrd *thrd, char *log);
int		ft_add_s_to_s(char *log, int ret, char *s);
int		ft_add_int_to_s(char *log, int ret, unsigned long int ts);
int		ft_write_ts(t_thrd *thrd, char *log);
int		ft_check_args(int argc, char **argv);
void	ft_usleep(struct timeval *current, int time);
int		ft_check_num(int argc, char **argv);

#endif