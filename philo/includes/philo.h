#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>

typedef enum s_error
{
    OK,
    INVALID_NUMBER,
    INVALID_CONTENT
} t_error_code;

# define ARG_ERROR_NUM "Invalid number of arguments. See subject.\n"
# define ARG_ERROR_CONTENT "One of your arguments is invalid, \
check subject and try again.\n"

typedef struct s_prg
{
    int test;
    char *str;
}t_prg;


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