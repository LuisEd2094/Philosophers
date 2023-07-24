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
	bool	av;
	pthread_mutex_t lock;
}	t_fork;

typedef struct s_philo
{
	struct s_prg	*prg;
	pthread_t		t1;
	int				id;
	int				eat_count;
	bool			status;
	bool			eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	t_fork			*r_fork;
	t_fork			*l_fork;
}	t_philo;

typedef struct s_prg
{
    pthread_t       *tid;
	int				num_threads;
    int             philo_num;
    int             meals_nb;
	int				err;
    bool            dead;
    bool            finished;
    t_philo         *philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
    t_fork			*forks;
    pthread_mutex_t lock;
} t_prg;


typedef enum s_error
{
	INIT_THREAD_ERROR = 10,
	MALLOC_ERROR,
	TIME_ERROR

} t_error_code;


# define INIT_THREAD_ERR_MSSG "There was an error when init a new thread, \
closing program.\n"
# define MALLOC_ERR_MSSG "There was an error allocating memory, \
closing program.\n"
# define TIME_ERR_MSG "There was an error getting current time, \
closing program.\n"

# define TAKE_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIED "died"

// PARSE ARGUMENTS API //
void    parse_arguments(int argc, char *argv[]);
//INIT FUNCTIONS //
void    init(t_prg *prg, char **argv, int argc);
void	init_mutex(pthread_mutex_t *thread, t_prg *prg);
// PRINT ERR FUNCTIONS //
void    print_err_prg(char *err, t_prg *prg);
// CLOSE PROGRAM FUNCTIONS //
void    close_prg(t_prg *prg);
// GET CURRENT TIMETIME //
uint64_t	get_time(t_prg *prg);
// ONE PHILE CASE //
void    one_philo_case(t_prg *prg);
// THREAD FUNCTIONS //
void	*routine(void *philo_pointer);
// ACTION FUNCTIONS //
bool	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void    drop_forks(t_philo *philo);
void    philo_sleep(t_philo *philo);



// PRINT MESSAGES //
void    print_philo_state(char *str, t_philo *philo);



#endif