/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inition.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:24:16 by annadanylev       #+#    #+#             */
/*   Updated: 2024/04/24 12:26:11 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	data_init(t_info *info)
{
	int	i;

	i = 0;
	info->phils = malloc(sizeof(t_phil) * info->num_phils);
	if (!info->phils)
		return (error_init(info));
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_phils);
	if (!info->forks)
		return (error_init(info));
	pthread_mutex_init(&info->death_mutti, NULL);
	pthread_mutex_init(&info->times_mutti, NULL);
	pthread_mutex_init(&info->write_mutti, NULL);
	while (i < info->num_phils)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	i = 0;
	start_philos(info);
	while (i < info->num_phils)
	{
		get_forks(&info->phils[i], i);
		i++;
	}
	return (0);
}

void	start_philos(t_info *info)
{
	int	i;

	i = 0;
	info->dead = 0;
	info->max_meals = 0;
	while (i < info->num_phils)
	{
		info->phils[i].last_meal = 0;
		info->phils[i].meals_num = 0;
		info->phils[i].info = info;
		info->phils[i].id = i + 1;
		i++;
	}
}

void	get_forks(t_phil *phil, int pos)
{
	phil->fork_r = &phil->info->forks[pos];
	if (phil->info->num_phils == pos + 1)
		phil->fork_l = &phil->info->forks[0];
	else
		phil->fork_l = &phil->info->forks[(pos + 1)];
}

void	memento_mori(t_info *info)
{
	int	i;
	int	d;

	d = 0;
	while (!someone_died(&info->phils[d]))
	{
		i = -1;
		while (++i < info->num_phils)
		{
			pthread_mutex_lock(&info->times_mutti);
			if (info->death_time <= (get_current_time() - info->start_time)
				- info->phils[i].last_meal)
			{
				rip(info, i + 1);
				return ;
			}
			pthread_mutex_unlock(&info->times_mutti);
		}
		d = 0;
	}
	return ;
}
