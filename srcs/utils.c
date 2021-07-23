/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:59:07 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 04:06:00 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_think(t_thrd *arg)
{
	char log[100];
	int	ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is thinking\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_eat(t_thrd *arg)
{
	char log[100];
	int	ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is eating\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_sleep(t_thrd *arg)
{
	char log[100];
	int	ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is sleeping\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_fork(t_thrd *arg)
{
	char log[100];
	int	ret;

	gettimeofday(&arg->current, NULL);
	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " has taken a fork\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_death(t_thrd *arg)
{
	char log[100];
	int	ret;

	ret = ft_write_ts_death(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " died\n");
	write(1, &log, ret);
}

int	ft_write_ts_death(t_thrd *thrd, char *log)
{
	unsigned long int	ts;
	int	ret;

	ts = (thrd->current_mstr.tv_sec * 1000 + thrd->current_mstr.tv_usec / 1000) - (thrd->init->tv_sec * 1000 + thrd->init->tv_usec / 1000);
	log[0] = '[';
	ret = ft_add_int_to_s(log, 1, ts);
	ret = ft_add_s_to_s(log, ret, " ms] ");
	return (ret);
}

int	ft_add_s_to_s(char *log, int ret, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		log[ret] = s[i];
		ret++;
		i++;
	}
	return (ret);
}

int	ft_add_int_to_s(char *log, int ret, unsigned long int ts)
{
	unsigned long int tmp;
	int	count;
	int	ret_bis;

	count = 1;
	tmp = ts;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		count++;
	}
	ret_bis = ret + count;
	if (ts == 0)
		log[ret + count - 1] = '0';
	while (ts > 0)
	{
		log[ret + count - 1] = ts % 10 + 48;
		ts = ts / 10;
		count--;
	}
	return (ret_bis);
}

int	ft_write_ts(t_thrd *thrd, char *log)
{
	unsigned long int	ts;
	int	ret;

	ts = (thrd->current.tv_sec * 1000 + thrd->current.tv_usec / 1000) - (thrd->init->tv_sec * 1000 + thrd->init->tv_usec / 1000);
	log[0] = '[';
	ret = ft_add_int_to_s(log, 1, ts);
	ret = ft_add_s_to_s(log, ret, " ms] ");
	return (ret);
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
	struct timeval	start;
	unsigned long int	dif;

	start = *current;
	dif = (current->tv_sec * 1000 + current->tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
	while (dif < (unsigned int)time)
	{
		usleep(100);
		gettimeofday(current, NULL);
		dif = (current->tv_sec * 1000 + current->tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
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
