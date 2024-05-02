/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadly_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:16:07 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/02 13:50:16 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	someone_died(t_info *info)
{
	pthread_mutex_lock(&info->death_mutti);
	if (info->dead == 1)
		{
			pthread_mutex_unlock(&info->death_mutti);
			return (1);
		}
	else
	{
		pthread_mutex_unlock(&info->death_mutti);
		return (0);
	}
}

int dont_overeat(t_phil *phil)
{
	pthread_mutex_lock(&phil->info->time_mutti);
	if (phil->meals_num == phil->info->max_meals)
	{
		phil->info->full++;
		pthread_mutex_unlock(&phil->info->time_mutti);
		return (1);
	}
	pthread_mutex_unlock(&phil->info->time_mutti);
	return (0);
}

void	rip(t_info *info, int i)
{
	long long elapsed;

	pthread_mutex_lock(&info->death_mutti);
	info->dead = 1;
	pthread_mutex_unlock(&info->death_mutti);
	elapsed = get_current_time() - info->start_time;
	pthread_mutex_lock(&info->write_mutti);
	printf("%llu R.I.P.: philosopher %d has died.\n", elapsed, i + 1);
	pthread_mutex_unlock(&info->write_mutti);
}