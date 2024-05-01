/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:10 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 17:13:01 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phil *phil)
{
	pthread_mutex_lock(phil->fork_r);
	writing(phil, 1);
	pthread_mutex_lock(phil->fork_l);
	writing(phil, 2);
	writing(phil, 3);
	pthread_mutex_lock(&phil->info->times_mutti);
	phil->last_meal = get_current_time();
	phil->meals_num++;
	phil->info->max_meals++;
	pthread_mutex_unlock(&phil->info->times_mutti);
	ft_usleep(phil->info->eat_time, phil);
	pthread_mutex_unlock(phil->fork_r);
	pthread_mutex_unlock(phil->fork_l);
}

void	sleepi(t_phil *phil)
{
	if (!someone_died(phil))
	{
		writing(phil, 4);
		ft_usleep(phil->info->sleep_time, phil);
	}
}

void	think(t_phil *phil)
{
	if (!someone_died(phil))
		writing(phil, 5);
}

void	writing(t_phil *phil, int action)
{
	long long	elapsed;

	elapsed = get_current_time() - phil->info->start_time;
	pthread_mutex_lock(&phil->info->write_mutti);
	if (action == 1 && !someone_died(phil))
		printf(Y "%-5llu" RESET G "Philosopher \
%d has taken a right fork.\n" RESET, elapsed, phil->id);
	else if (action == 2 && !someone_died(phil))
		printf(Y "%-5llu" RESET PUR "Philosopher \
%d has taken a left fork.\n" RESET, elapsed, phil->id);
	else if (action == 3 && !someone_died(phil))
		printf(Y "%-5llu" RESET P "Philosopher %d is eating.\n" RESET, elapsed,
			phil->id);
	else if (action == 4 && !someone_died(phil))
		printf(Y "%-5llu" RESET B "Philosopher %d is sleeping.\n" RESET,
			elapsed, phil->id);
	else if (action == 5 && !someone_died(phil))
		printf(Y "%-5llu" RESET O "Philosopher %d is thinking.\n" RESET,
			elapsed, phil->id);
	pthread_mutex_unlock(&phil->info->write_mutti);
}

int	someone_died(t_phil *phil)
{
	int	i;

	pthread_mutex_lock(&phil->info->times_mutti);
	pthread_mutex_unlock(&phil->info->times_mutti);
	i = 0;
	pthread_mutex_lock(&phil->info->death_mutti);
	i = phil->info->dead;
	pthread_mutex_unlock(&phil->info->death_mutti);
	return (i);
}
