/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:38 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 15:15:03 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 5 || argc == 6)
	{
		if (parsing(argc, argv, &info))
		{
			write(2, "Very bad input\n", 16);
			return (1);
		}
		if (data_init(&info))
			return (1);
		process_start(&info);
		free_all(&info);
	}
	else
	{
		printf(PUR "Wrong input\n" RESET);
		return (1);
	}
	return (0);
}

void	rip(t_info *info, int d)
{
	long long	elapsed;

	pthread_mutex_lock(&info->death_mutti);
	info->dead = 1;
	pthread_mutex_unlock(&info->death_mutti);
	elapsed = get_current_time() - info->start_time;
	printf(Y "%-5llu" RESET Y "R.I.P.: philosopher %d has died.\n", elapsed, d);
	pthread_mutex_unlock(&info->times_mutti);
}

int	error_init(t_info *info)
{
	write(2, "Malloc issue\n", 14);
	free_all(info);
	return (1);
}
