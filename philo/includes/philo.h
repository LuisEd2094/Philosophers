#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>


struct	s_prg;

typedef struct s_philo
{
	struct s_prg	*prg;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	bool			status;
	bool			eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_prg
{
    pthread_t       *tid;
    int             philo_num;
    int             meals_nb;
    bool            dead;
    bool            finished;
    t_philo         *philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t lock;
    pthread_mutex_t write;
} t_prg;


typedef enum s_error
{
    OK,

} t_error_code;


#define INIT_THREAD_ERROR "There was an error when init a new thread, closing\
program.\n"

// PARSE ARGUMENTS API //
void    parse_arguments(int argc, char *argv[]);
//PRG FUNCTIONS //
void    init(t_prg *prg, char **argv, int argc);
// ERROR FUNCTIONS //
void    print_err_prg(char *err, t_prg *prg);
// CLOSE PROGRAM FUNCTIONS //
void    close_prg(t_prg *prg);


#endif