/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:38 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/05 14:52:49 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lonely_philo(t_info *info)
{
	long long	elapsed;

	elapsed = 0;
	printf("%llu Philosopher 1 has taken a right fork.\n",
		elapsed);
	ft_usleep(info->death_time, &info->phils[0]);
	elapsed += info->death_time;
	printf("%llu R.I.P.: philosopher 1 has died.\n",
		elapsed);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	free(info->phils);
	while (i < info->num_phils)
	{
		if (info->forks)
			pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
}

void	big_error(t_info *info)
{
	printf("Error with thread creation\n");
	free_all(info);
}

int	main(int argc, char **argv)
{
	t_info	info;
	
	if (argc == 5 || argc == 6)
	{
		if (!parsing(argc, argv, &info))
		{
			if (data_init(&info))
			{
				free_all(&info);
				return (1);
			}
			if (info.num_phils == 1)
			{
				lonely_philo(&info);
				return (0);
			}
			start_dinner(&info);
			//monitor(&info);
			//thread_love(&info);
			free_all(&info);
			return (0);
		}
		else
		{
			printf("Wrong input format\n");
			return (1);
		}
	}
	return (1);
}
