#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_prg
{
    pthread_t       *tid;
    int             philo_num;
    int             meals_nb;
    int             dead;
    int             finished;
    int             death_time;
    int             eat_time;
    int             sleep_time;
    int             start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t lock;
    pthread_mutex_t write;
} t_prg;


//ERRORS//
void    parse_arguments(int argc, char *argv[]);

#endif