/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:38:24 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/02 21:27:11 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *aux)
{
	t_phil	*phil;
	
	phil = (t_phil *)aux;

	if (phil->id % 2)
		ft_usleep(100, phil);
	while(!someone_died(phil->info))
	{
		eat(phil);
		sleep_think(phil);
		if (dont_overeat(phil))
			break;
	}
	return (NULL);
}

void	monitor(t_info *info)
{
	int	i;
	
	while (1)
	{
		i = -1;
		pthread_mutex_lock(&info->time_mutti);
		if (info->full >= info->num_phils)
		{
			pthread_mutex_unlock(&info->time_mutti);
			return ;
		}
		while (++i < info->num_phils)
		{
			if (info->death_time <= (get_current_time() - info->start_time) - info->phils[i].last_meal)
			{
				pthread_mutex_unlock(&info->time_mutti);
				rip(info, i);
				return ;
			}
		}
		pthread_mutex_unlock(&info->time_mutti);
	}
}

void	start_dinner(t_info *info)
{
	int i;

	i = -1;
	info->start_time = get_current_time();
	while (++i < info->num_phils)
	{
		if (pthread_create(&info->phils[i].philo_thread, NULL, routine,
					&info->phils[i]))
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