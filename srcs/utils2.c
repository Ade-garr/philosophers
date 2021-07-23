/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:30:19 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/23 19:39:24 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write_think(t_thrd *arg)
{
	char	log[100];
	int		ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is thinking\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_eat(t_thrd *arg)
{
	char	log[100];
	int		ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is eating\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_sleep(t_thrd *arg)
{
	char	log[100];
	int		ret;

	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " is sleeping\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_fork(t_thrd *arg)
{
	char	log[100];
	int		ret;

	gettimeofday(&arg->current, NULL);
	ret = ft_write_ts(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " has taken a fork\n");
	if (*arg->end == 0)
		write(1, &log, ret);
}

void	ft_write_death(t_thrd *arg)
{
	char	log[100];
	int		ret;

	ret = ft_write_ts_death(arg, log);
	ret = ft_add_int_to_s(log, ret, arg->id);
	ret = ft_add_s_to_s(log, ret, " died\n");
	write(1, &log, ret);
}
