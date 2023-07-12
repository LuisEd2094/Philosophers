#ifndef PHILO_H
# define PHILO_H

typedef enum s_error
{
    OK,
    INVALID_NUMBER,
    INVALID_CONTENT
}t_error_code;

//ERRORS//
void    print_err(t_error_code err);
void    check_arguments(int argc, char *argv[]);


//LIBFT FUNCTIONS//
int ft_isdigit(int c);


#endif