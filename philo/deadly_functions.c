/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadly_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:16:07 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/05 17:58:04 by annadanylev      ###   ########.fr       */
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

void	rip(t_info *info, int i)
{
	long long elapsed;

	pthread_mutex_lock(&info->death_mutti);
	info->dead = 1;
	pthread_mutex_unlock(&info->death_mutti);
	elapsed = get_current_time() - info->phils[i].start;
	pthread_mutex_lock(&info->write_mutti);
	printf("%llu R.I.P.: philosopher %d has died.\n", elapsed, i + 1);
	pthread_mutex_unlock(&info->write_mutti);
}