/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:29:11 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/15 02:14:16 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	c = nb % 10 + 48;
	write(fd, &c, 1);
}
