/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:10 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/02 21:33:59 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phil *phil)
{
	pthread_mutex_lock(phil->fork_r);
	writing(phil, "has taken a right fork");
	pthread_mutex_lock(phil->fork_l);
	writing(phil, "has taken a left fork");
	writing(phil, "is eating");
	pthread_mutex_lock(&phil->info->time_mutti);
	phil->last_meal = get_current_time() - phil->info->start_time;
	pthread_mutex_unlock(&phil->info->time_mutti);
	phil->meals_num++;
	ft_usleep(phil->info->eat_time, phil);
	pthread_mutex_unlock(phil->fork_r);
	pthread_mutex_unlock(phil->fork_l);
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