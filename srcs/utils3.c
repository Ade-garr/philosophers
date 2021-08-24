/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:31:41 by ade-garr          #+#    #+#             */
/*   Updated: 2021/08/24 15:29:25 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_write_ts_death(t_thrd *thrd, char *log)
{
	unsigned long int	ts;
	int					ret;

	ts = (thrd->current_mstr.tv_sec * 1000 + thrd->current_mstr.tv_usec / 1000) \
	- (thrd->init->tv_sec * 1000 + thrd->init->tv_usec / 1000);
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
	unsigned long int	tmp;
	int					count;
	int					ret_bis;

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
	int					ret;

	ts = (thrd->current.tv_sec * 1000 + thrd->current.tv_usec / 1000) - \
	(thrd->init->tv_sec * 1000 + thrd->init->tv_usec / 1000);
	log[0] = '[';
	ret = ft_add_int_to_s(log, 1, ts);
	ret = ft_add_s_to_s(log, ret, " ms] ");
	return (ret);
}

int	ft_check_end(t_thrd *arg)
{
	pthread_mutex_lock(&*arg->stop);
	if (*arg->end == 1)
	{
		pthread_mutex_unlock(&*arg->stop);
		return (1);
	}
	pthread_mutex_unlock(&*arg->stop);
	return (0);
}
