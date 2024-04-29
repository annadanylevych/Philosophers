/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:54:07 by annadanylev       #+#    #+#             */
/*   Updated: 2024/04/29 14:03:48 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


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
