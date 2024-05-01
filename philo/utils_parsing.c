/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:38:33 by adanylev          #+#    #+#             */
/*   Updated: 2024/04/20 17:57:02 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	free_phil(t_phil *phil)
{
	pthread_mutex_destroy(phil->fork_r);
	pthread_mutex_destroy(phil->fork_l);
}

void	free_fork(t_fork *fork)
{
	pthread_mutex_destroy(&fork->fork);
	free(fork);
}

void	big_error(t_info *info)
{
	printf("BIG ERROR\n");
	free_all(info);
}
