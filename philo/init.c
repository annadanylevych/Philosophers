/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:09 by annadanylev       #+#    #+#             */
/*   Updated: 2024/04/30 17:02:11 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void    philos_init(t_phil *phil)
{
    phil->id = i + 1;
    phil->meals_num = 0;
    phil->last_meal = 0;
}


void    data_init(t_info *info)
{
    int     i;

    i = 0;

}