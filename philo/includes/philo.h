/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:32 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/09/04 11:03:47 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

struct	s_prg;

typedef struct s_forks
{
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	struct s_prg	*prg;
	pthread_t		t1;
	int				id;
	int				eat_count;
	bool			can_continue;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	t_fork			*r_fork;
	t_fork			*l_fork;
}	t_philo;

typedef struct s_prg
{
	pthread_t		*tid;
	int				num_threads;
	int				philo_num;
	int				meals_nb;
	int				err;
	char			*err_msg;
	bool			dead;
	bool			can_start;
	int				finished;
	t_philo			*philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	t_fork			*forks;
	pthread_mutex_t	lock;
}	t_prg;

typedef enum s_error
{
	INIT_MUTEX_ERROR = 10,
	MALLOC_ERROR,
	TIME_ERROR,
	THREAD_CREATE_ERROR
}	t_error_code;

# define INIT_MUTEX_ERR_MSSG "There was an error when init a new mutex, \
closing program.\n"
# define MALLOC_ERR_MSSG "There was an error allocating memory, \
closing program.\n"
# define TIME_ERR_MSG "There was an error getting current time, \
closing program.\n"
# define THREAD_CREATE_ERROR_MSG "There was an error creating a new thread, \
closing program.\n"

# define TAKE_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIED "died"

// PARSE ARGUMENTS API //
void		parse_arguments(int argc, char *argv[]);
//INIT FUNCTIONS //
void		init(t_prg *prg, char **argv, int argc);
bool		init_mutex(pthread_mutex_t *thread, t_prg *prg);
// PRINT ERR FUNCTIONS //
// CLOSE PROGRAM FUNCTIONS //
void		close_prg(t_prg *prg);
void		close_on_failed_init(t_prg *prg);
void		free_mallocs(t_prg *prg);
// GET CURRENT TIMETIME //
uint64_t	get_time(t_prg *prg);
// ONE PHILE CASE //
void		one_philo_case(t_prg *prg);
// ELSE CASE //
void		work_more_one_philo(t_prg *prg);
// THREAD FUNCTIONS //
void		*routine(void *philo_pointer);
void		*supervisor(void *philo_p);
// ACTION FUNCTIONS //
void		take_forks(t_philo *philo);
void		eat(t_philo *philo);
void		drop_forks(t_philo *philo);
void		philo_sleep(t_philo *philo);
// THREAD HANDLE FUNCTIONS//
void		*update_num_threads(t_prg *prg, int value);
bool		create_thread(pthread_t *tid, void *(*f)(void *), t_philo *philo_p);
bool		check_conditions_continue_thread(t_philo *philo);
// PRINT MESSAGES //
void		print_philo_state(char *str, t_philo *philo);

#endif
