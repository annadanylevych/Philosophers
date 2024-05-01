/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadly_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:16:07 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/01 16:21:49 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	someone_died(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&info->death_mutti);
	if (info->dead == 1)
		{
			pthread_mutex_unlock(&info->death_mutti);
			return (1);
		}
	else
	{
		pthread_mutex_unlock(&info->death_mutti);
		return (0);
	}
}