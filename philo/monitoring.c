/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:31:44 by annadanylev       #+#    #+#             */
/*   Updated: 2024/05/09 11:48:50 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_full(t_phil *phil)
{
	if (phil->info->max_meals > 0)
	{
		if (phil->meals_num >= phil->info->max_meals)
			return (1);
	}
	return (0);
}

void	*monitor(t_info *info)
{
	int		full_count;
	int		i;

	while (1)
	{
		i = -1;
		full_count = 0;
		pthread_mutex_lock(&info->time_mutti);
		while (++i < info->num_phils)
		{
			if (get_current_time() - info->start_time
				- info->phils[i].last_meal >= info->death_time)
			{
				rip(info, i);
				return (pthread_mutex_unlock(&info->time_mutti), NULL);
			}
			if (is_full(&info->phils[i]))
				full_count++;
		}
		if (full_count == info->num_phils)
			return (pthread_mutex_unlock(&info->time_mutti), NULL);
		pthread_mutex_unlock(&info->time_mutti);
		usleep(2000);
	}
}
