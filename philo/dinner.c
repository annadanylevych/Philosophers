/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:38:24 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/05 17:35:32 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *aux)
{
	t_phil	*phil;
	
	phil = (t_phil *)aux;
	while (!someone_died(phil->info))
	{
		take_forks(phil);
        if (someone_died(phil->info)) 
		{
			pthread_mutex_unlock(phil->fork_r);
    	    pthread_mutex_unlock(phil->fork_l);
		}
		eat(phil);
        if (someone_died(phil->info))
            return (NULL);
		if (phil->meals_num >= phil->info->max_meals && phil->info->max_meals > 0)
            break; 
        sleep_think(phil);
		if (someone_died(phil->info))
            return (NULL);
    }
    return (NULL);
}

void	start_dinner(t_info *info)
{
	int i;

	i = -1;
	info->start_time = get_current_time();
	while (++i < info->num_phils)
	{
		info->phils[i].start = get_current_time();
		if (pthread_create(&info->phils[i].philo_thread, NULL, &routine,
					(void *)&info->phils[i]))
		{
			big_error(info);
			return ;
		}
	}
	monitor(info);
	i = -1;
	while (++i < info->num_phils)
	{
		if (pthread_join(info->phils[i].philo_thread, NULL))
		{
			big_error(info);
			return ;
		}
	}
}