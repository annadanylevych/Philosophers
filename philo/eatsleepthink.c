/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:10 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/05 14:59:48 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_forks(t_phil *phil)
{
	if (phil->id % 2 == 0) 
        pthread_mutex_lock(phil->fork_r);
	else 
	    pthread_mutex_lock(phil->fork_l);
	if (!someone_died(phil->info))
		writing(phil, "has taken a fork");
	if (phil->id % 2 == 0) 
	{
		if (pthread_mutex_lock(phil->fork_l) != 0)
			return (pthread_mutex_unlock(phil->fork_r), 1);
		if (!someone_died(phil->info))
			writing(phil, "has taken a fork");
	}	
    else
	{
		if (pthread_mutex_lock(phil->fork_r) != 0)
			return (pthread_mutex_unlock(phil->fork_l), 1);
		if (!someone_died(phil->info))
			writing(phil, "has taken a fork");			
	}
	return (0);
}

void	eat(t_phil *phil)
{
	writing(phil, "is eating");
	pthread_mutex_lock(&phil->info->time_mutti);
	phil->last_meal = get_current_time() - phil->info->start_time;
	phil->time_to_die = phil->last_meal + phil->info->death_time;
	pthread_mutex_unlock(&phil->info->time_mutti);
	ft_usleep(phil->info->eat_time, phil);
	pthread_mutex_lock(&phil->info->time_mutti);
	phil->meals_num++;
	pthread_mutex_unlock(&phil->info->time_mutti);
    pthread_mutex_unlock(phil->fork_l);
	pthread_mutex_unlock(phil->fork_r);
}


void	sleep_think(t_phil *phil)
{
	if (!someone_died(phil->info))
	{
		writing(phil, "is sleeping");
		ft_usleep(phil->info->sleep_time, phil);
	}
	if (!someone_died(phil->info))
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