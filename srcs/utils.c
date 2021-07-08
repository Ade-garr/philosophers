/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:59:07 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/08 13:26:26 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
