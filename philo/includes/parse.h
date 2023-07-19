#ifndef PARSE_H
# define PARSE_H

# include <stddef.h>
# include <pthread.h>

typedef enum s_error
{
    OK,
    INVALID_NUMBER,
    INVALID_CONTENT,
    INVALID_PHILOS,
    INVALID_TIME,
    INVALID_VALUE,
    NO_INT_VALUE
} t_error_code;

# define MAX_PHILOS 300
# define MAX_TIME   20000

# define ARG_ERROR_NUM "Invalid number of arguments. See subject.\n"
# define ARG_ERROR_CONTENT "One of your arguments is invalid, \
check your arguments and try again.\n"
# define ARG_INVALID_PHILOS "You have given too many Philos, \
the max number accepted is 300.\n"
# define ARG_INVALID_TIME "The max time to die, eat and/or think accepted is  \
20000.\n"
# define ARG_ZERO_VALUE "Arguments can't have zero or negative value.\n"
# define ARG_INT_VALUE "Please provide an int value for an argument.\n"



 //ERRORS//

void    print_err(int err);
void    check_arguments(int argc, char *argv[]);
void    remove_white_space_arguments(char *argv[]);


//LIBFT FUNCTIONS//
int     check_if_int(char *str);
int     ft_isspace(char chr);
size_t  ft_strlen(const char *s);
void    remove_white_space(char *argv);
int     check_if_white_right_left(char *argv);
int     get_sign(char *argv);
int     ft_atoi(const char *nptr);
void    remove_zeros(char *str);

#endif