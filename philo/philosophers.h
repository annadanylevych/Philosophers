/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annadanylevych <annadanylevych@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:13:50 by adanylev          #+#    #+#             */
/*   Updated: 2024/05/02 11:39:31 by annadanylev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_phil
{
	struct s_info	*info;
	int				id;
	pthread_t		philo_thread;
	int				meals_num;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	long long		last_meal;
}					t_phil;

typedef struct s_info
{
	int				full;
	int				max_meals;
	int				num_phils;
	t_phil			*phils;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	pthread_mutex_t	*forks;
	int				dead;
	long long		start_time;
	pthread_mutex_t	death_mutti;
	pthread_mutex_t	write_mutti;
	pthread_mutex_t	time_mutti;
}					t_info;

void   				data_init(t_info *info);
void				big_error(t_info *info);
int					check_input(char **argv);
long long			ft_atol(char *argv);
int					parsing(int argc, char **argv, t_info *info);
int					ft_strlen(char *s);
int					ft_strncmp(char *s1, char *s2, int n);
void				ft_usleep(long long time, t_phil *phil);
long long			get_current_time(void);
void				lonely_philo(t_info *info);
int					error_init(t_info *info);
int					someone_died(t_info *info);
void				start_dinner(t_info *info);
void				eat(t_phil *phil);
void				sleep_think(t_phil *phil);
void				writing(t_phil *phil, char *msg);
int 				dont_overeat(t_phil *phil);
void				rip(t_info *info, int i);


#endif
