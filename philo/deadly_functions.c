/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadly_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:38:21 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/09 11:38:49 by adanylev         ###   ########.fr       */
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
	long long	elapsed;

	pthread_mutex_lock(&info->death_mutti);
	info->dead = 1;
	pthread_mutex_unlock(&info->death_mutti);
	elapsed = get_current_time() - info->start_time;
	pthread_mutex_lock(&info->write_mutti);
	printf("%llu R.I.P.: philosopher %d has died.\n", elapsed, i + 1);
	pthread_mutex_unlock(&info->write_mutti);
}
