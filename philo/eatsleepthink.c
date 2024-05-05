/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:10 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/05 19:08:36 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_phil *phil)
{
	if (phil->id % 2 == 0)
	{ 
        pthread_mutex_lock(phil->fork_r);
		writing(phil, "has taken a fork");
	    pthread_mutex_lock(phil->fork_l);
		writing(phil, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(phil->fork_l);
		writing(phil, "has taken a fork");
		pthread_mutex_lock(phil->fork_r);
		writing(phil, "has taken a fork");			
	}
	return (0);
}

void	eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->info->time_mutti);
	phil->last_meal = get_current_time() - phil->info->start_time;
	phil->meals_num++;
	pthread_mutex_unlock(&phil->info->time_mutti);
	writing(phil, "is eating");
	ft_usleep(phil->info->eat_time, phil);
	if (phil->id % 2 == 0)
	{ 
        pthread_mutex_unlock(phil->fork_r);
	    pthread_mutex_unlock(phil->fork_l);
	}
	else
	{
		pthread_mutex_unlock(phil->fork_l);
		pthread_mutex_unlock(phil->fork_r);
	}
}


void	sleep_think(t_phil *phil)
{
	writing(phil, "is sleeping");
	ft_usleep(phil->info->sleep_time, phil);
	writing(phil, "is thinking");
}

void	writing(t_phil *phil, char *msg)
{
	long long	elapsed;

	elapsed = get_current_time() - phil->info->start_time;
	if (!someone_died(phil->info))
	{
		pthread_mutex_lock(&phil->info->write_mutti);
		printf ("%llu Philosopher %d %s.\n", elapsed, phil->id, msg);
		pthread_mutex_unlock(&phil->info->write_mutti);
	}
}