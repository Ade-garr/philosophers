/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:59:07 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/15 04:54:13 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_think(t_thrd *arg)
{
	pthread_mutex_lock(arg->syscl);
	ft_write_ts(arg);
	write(1, " philo ", 7);
	ft_putnbr_fd(arg->id, 1);
	write(1, " is thinking\n", 13);
	pthread_mutex_unlock(arg->syscl);
}

void	ft_write_eat(t_thrd *arg)
{
	pthread_mutex_lock(arg->syscl);
	ft_write_ts(arg);
	write(1, " philo ", 7);
	ft_putnbr_fd(arg->id, 1);
	write(1, " is eating\n", 11);
	pthread_mutex_unlock(arg->syscl);
}

void	ft_write_sleep(t_thrd *arg)
{
	pthread_mutex_lock(arg->syscl);
	ft_write_ts(arg);
	write(1, " philo ", 7);
	ft_putnbr_fd(arg->id, 1);
	write(1, " is sleeping\n", 13);
	pthread_mutex_unlock(arg->syscl);
}

void	ft_write_fork(t_thrd *arg)
{
	pthread_mutex_lock(arg->syscl);
	ft_write_ts(arg);
	write(1, " philo ", 7);
	ft_putnbr_fd(arg->id, 1);
	write(1, " has taken a fork\n", 18);
	pthread_mutex_unlock(arg->syscl);
}

void	ft_write_ts(t_thrd *thrd)
{
	unsigned int	ts;

	gettimeofday(&thrd->current, NULL);
	ts = (thrd->current.tv_sec - thrd->init->tv_sec) * 1000 + (thrd->current.tv_usec - thrd->init->tv_usec) / 1000;
	write(1, "[", 1);
	ft_putnbr_fd(ts, 1);
	write(1, " ms]", 4);
}

useconds_t	ft_conv_ms(int ms)
{
	unsigned long int	conv;

	conv = ms * 1000;
	return (conv);
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
