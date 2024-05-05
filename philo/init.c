/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:49:09 by annadanylev       #+#    #+#             */
/*   Updated: 2024/05/05 19:23:30 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    get_forks(t_phil *phil, int i)
{
    phil->fork_r = &phil->info->forks[i];
    phil->fork_l = &phil->info->forks[(i + 1) % phil->info->num_phils];
}

void    philos_init(t_info *info)
{
    int     i;

    i = -1;
    while (++i < info->num_phils)
    {
        info->phils[i].id = i + 1;
        info->phils[i].meals_num = 0;
        info->phils[i].last_meal = get_current_time();
        info->phils[i].info = info;
        get_forks(&info->phils[i], i);
    }
}


int    data_init(t_info *info)
{
    int     i;

    i = -1;
    info->dead = 0;
    info->phils = malloc(sizeof(t_phil) * info->num_phils);
    if (!info->phils)
        return  (1);
    info->forks = malloc(sizeof(pthread_mutex_t) * info->num_phils);
    if (!info->forks)
        return (1);
    while (++i < info->num_phils)
        pthread_mutex_init(&info->forks[i], NULL);
    pthread_mutex_init(&info->write_mutti, NULL);
    pthread_mutex_init(&info->death_mutti, NULL);
    pthread_mutex_init(&info->time_mutti, NULL);
    philos_init(info);
    return (0);
}