/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:48:02 by ade-garr          #+#    #+#             */
/*   Updated: 2021/07/13 14:50:23 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_rout_phl(t_philo *philo)
{
    while (philo->setup != 1)
    {
        if (philo->setup == 2)
            return (1);
    }
}