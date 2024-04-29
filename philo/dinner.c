/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:54:07 by annadanylev       #+#    #+#             */
/*   Updated: 2024/04/23 17:02:02 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *phil)
{
	t_phil	*aux;

	aux = (t_phil *)phil;
	if (aux->id % 2 != 0)
		ft_usleep(10, aux);
	while (!someone_died(aux))
	{
		eat(aux);
		sleepi(aux);
		think(aux);
		pthread_mutex_lock(&aux->info->times_mutti);
		if (aux->info->max_meals / aux->info->num_phils == aux->info->num_meals)
		{
			pthread_mutex_unlock(&aux->info->times_mutti);
			pthread_mutex_lock(&aux->info->death_mutti);
			aux->info->dead = 1;
			pthread_mutex_unlock(&aux->info->death_mutti);
		}
		pthread_mutex_unlock(&aux->info->times_mutti);
	}
	return (NULL);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	free(info->phils);
	i = 0;
	while (i < info->num_phils)
	{
		if (info->forks)
			pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
}

void	process_start(t_info *info)
{
	int	i;

	i = -1;
	info->start_time = get_current_time();
	if (info->num_meals == 0)
		return ;
	else if (info->num_phils == 1)
		lonely_philo(info);
	else
	{
		while (++i < info->num_phils)
		{
			if (pthread_create(&info->phils[i].philo_thread, NULL, routine,
					&info->phils[i]))
				big_error(info);
		}
		i = -1;
		memento_mori(info);
		while (++i < info->num_phils)
		{
			if (pthread_join(info->phils[i].philo_thread, NULL))
				big_error(info);
		}
	}
}

void	ft_usleep(u_int64_t time, t_phil *phil)
{
	u_int64_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < time)
	{
		if (!someone_died(phil))
			usleep(time / 10);
		else
			return ;
	}
}

u_int64_t	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
