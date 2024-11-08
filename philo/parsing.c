/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:23:29 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 14:31:17 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(int argc, char **argv, t_info *info)
{
	if (argc < 2 || argc > 6)
		return (1);
	if (check_input(argv))
		return (1);
	info->num_phils = ft_atol(argv[1]);
	if (info->num_phils <= 0 || info->num_phils > 200)
		return (1);
	info->death_time = ft_atol(argv[2]);
	info->eat_time = ft_atol(argv[3]);
	info->sleep_time = ft_atol(argv[4]);
	if (argv[5])
		info->max_meals = ft_atol(argv[5]);
	else
		info->max_meals = -1;
	if (info->death_time == 0 || info->eat_time == 0 || info->sleep_time == 0
		|| info->max_meals == 0 || info->num_phils == 0
		|| info->num_phils > 200)
		return (1);
	return (0);
}

long long	ft_atol(char *argv)
{
	long long	n;

	if (ft_strlen(argv) > 26)
		return (0);
	if (ft_strlen(argv) == 26 && (ft_strncmp("18,446,744,073,709,551,615", argv,
				26) >= 0))
		return (0);
	n = 0;
	while (*argv)
	{
		if (*argv < '0' || *argv > '9')
			return (0);
		n = n * 10 + (*argv - '0');
		argv++;
	}
	return (n);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
