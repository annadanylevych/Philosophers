/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:38 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 14:33:19 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	lonely_philo(t_info *info)
{
	u_int64_t	elapsed;

	elapsed = get_current_time() - info->start_time;
	printf("%-5llu" "Philosopher 1 has taken a right fork.\n",
		elapsed);
	ft_usleep(info->death_time, &info->phils[0]);
	elapsed += info->death_time;
	printf("%-5llu" "R.I.P.: philosopher 1 has died.\n",
		elapsed);
}*/

int	main(int argc, char **argv)
{
	t_info	info;
	
	if (argc == 5 || argc == 6)
	{
		if (!parsing(argc, argv, &info))
		{
			data_init(&info);
		}
	}
	
	return (0);
}
