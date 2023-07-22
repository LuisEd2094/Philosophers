#include <parse.h>

static void    check_and_remove_white_space(char *argv)
{
    if (check_if_white_right_left(argv))
            remove_white_space(argv);
}


void parse_arguments(int argc, char *argv[])
{
    int i;

    i = 1;
    while (argv[i])
    {
        check_and_remove_white_space(argv[i]);
        check_and_remove_zeros(argv[i]);
        i++;
    }
    check_arguments(argc, argv);
}