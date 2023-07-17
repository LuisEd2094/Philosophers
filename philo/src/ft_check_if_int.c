int	check_last_digit(int sign, char *argv, int i)
{
	if (argv[i + 1] != '\0')
		return (0);
	if (sign == -1)
	{
		if ('8' - argv[i] >= 0)
			return (1);
		return (0);
	}
	else
	{	
		if ('7' - argv[i] >= 0)
			return (1);
		return (0);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


void	check_white_space(int *k, char *argv)
{
	while (argv[*k] != '+' && argv[*k] != '-' && !ft_isdigit(argv[*k]))
	{
		if (argv[(*k)] == '\f' || argv[(*k)] == '\n' \
		|| argv[(*k)] == '\r' || argv[(*k)] == '\t' \
		|| argv[(*k)] == '\t' || argv[(*k)] == ' ')
		{
			(*k) += 1;
		}

	}
}

int	get_sign(int *k, int *white, char *argv)
{
	int	sign;

	check_white_space(k , argv);
	*white = *k;
	sign = 0;
	if ((argv[(*k)] == '-' || argv[*k] == '+') && ft_isdigit(argv[*k + 1]))
	{
		if (argv[*k] == '-' )
			sign = -1;
		else if (argv[*k] == '+')
			sign = 1;
		(*k)++;
	}
	else
		sign = 0;
	return (sign);
}

int	check_if_int(char *str)
{
	int	i;
	int	white;
	int	sign;

	i = 0;
	white = 0;
	sign = get_sign(&i, &white, str);
	while (str[i])
	{
		if ((sign && (i - white) == 10) || (!sign && (i - white) == 9))
			return (check_last_digit(sign, str, i));
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}