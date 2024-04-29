/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:07:38 by adanylev          #+#    #+#             */
/*   Updated: 2024/04/29 14:01:29 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	(void)argv;
	if (!parsing(argc, argv, &info))
	{
		printf("%d\n", info.num_phils);
		printf("%llu\n", info.death_time);
		printf("%llu\n", info.eat_time);
		printf("%llu\n", info.sleep_time);
		printf("%d\n", info.num_meals);
	}
		
	return (0);
}
