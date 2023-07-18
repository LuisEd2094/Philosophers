#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <pthread.h>


typedef enum s_error
{
    OK,
    INVALID_NUMBER,
    INVALID_CONTENT,
    INVALID_PHILOS,
    INVALID_TIME,
    INVALID_VALUE
} t_error_code;

# define MAX_PHILOS 300
# define MAX_TIME   20000

# define ARG_ERROR_NUM "Invalid number of arguments. See subject.\n"
# define ARG_ERROR_CONTENT "One of your arguments is invalid, \
check subject and try again.\n"
# define ARG_INVALID_PHILOS "You have given too many Philos, \
the max number accepted is 300.\n"
# define ARG_INVALID_TIME "The max time to die, eat and/or think accepted is  \
20000.\n"
# define ARG_ZERO_VALUE "Arguments can't have zero or negative value.\n"





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
void    print_err(int err);
void    check_arguments(int argc, char *argv[]);


//LIBFT FUNCTIONS//
int     check_if_int(char *str);
int     ft_isspace(char chr);
size_t  ft_strlen(const char *s);
void    remove_white_space(char *argv);
int     check_if_white_right_left(char *argv);
int     get_sign(char *argv);
int     ft_atoi(const char *nptr);


#endif