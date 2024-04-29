/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:13:50 by adanylev          #+#    #+#             */
/*   Updated: 2024/04/29 14:01:48 by adanylev         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

typedef struct s_phil
{
	struct s_info	*info;
	int				id;
	pthread_t		philo_thread;
	int				meals_num;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	u_int64_t		last_meal;
}					t_phil;

typedef struct s_info
{
	int				max_meals;
	int				num_phils;
	int				num_meals;
	t_phil			*phils;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	pthread_mutex_t	*forks;
	int				dead;
	u_int64_t		start_time;
	pthread_mutex_t	death_mutti;
	pthread_mutex_t	write_mutti;
	pthread_mutex_t	times_mutti;
}					t_info;

void				free_fork(t_fork *fork);
void				free_phil(t_phil *phil);
void				free_all(t_info *info);
void				big_error(t_info *info);
int					check_input(char **argv);
long long			ft_atol(char *argv);
int					parsing(int argc, char **argv, t_info *info);
int					ft_strlen(char *s);
int					ft_strncmp(char *s1, char *s2, int n);
int					data_init(t_info *info);
void				start_philos(t_info *info);
void				get_forks(t_phil *phil, int pos);
void				eat(t_phil *phil);
void				sleepi(t_phil *phil);
void				think(t_phil *phil);
void				*routine(void *phil);
void				big_error(t_info *info);
void				process_start(t_info *info);
void				ft_usleep(u_int64_t time, t_phil *phil);
u_int64_t			get_current_time(void);
void				writing(t_phil *phil, char *msg);
int					someone_died(t_phil *phil);
void				lonely_philo(t_info *info);
void				memento_mori(t_info *info);
int					error_init(t_info *info);
void				rip(t_info	*info, int d);

#endif
