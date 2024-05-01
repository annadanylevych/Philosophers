/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:38:24 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 17:01:05 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *aux)
{
	t_phil	*phil;
	
	phil = (t_phil *)aux;
	if (phil->id % 2)
		usleep(15000);
	while(!someone_died)
	{
		eat(phil);
	}
}

void	start_dinner(t_info *info)
{
	int i;

	i = -1;
	if (info->num_phils == 1)
		lonely_philo(info);
	info->start_time = get_current_time();
	while (++i < info->num_phils)
	{
		if (pthread_create(&info->phils[i].philo_thread, NULL, routine,
					&info->phils[i]))
				big_error(info);
			if ()
			info->phils[i].last_meal = get_current_time();
	}
	monitor(info)
}