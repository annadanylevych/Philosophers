/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepthink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:10 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 17:12:11 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->fork_r);
	writing(phil, "has taken a right fork");
	pthread_mutex_lock(&phil->fork_l);
	writing(phil, "has taken a left fork");
	pthread_mutex_lock(&phil->info->time_mutti);
	phil->last_meal = 
	

}

void	writing(t_phil *phil, char *msg)
{
	long long	elapsed;

	elapsed = get_current_time() - phil->info->start_time;
	pthread_mutex_lock(&phil->info->write_mutti);
	printf ("%llu Philosopher %d %s.\n", elapsed, phil->id, msg);
	pthread_mutex_unlock(&phil->info->write_mutti);
}