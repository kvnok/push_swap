/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errorcheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:34:46 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 18:12:53 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exit(1) : operation not permitted or another problem has occured
//mode 1 only used in the case of longcalloc func in fillstack.c
//mode 2 everywhere else
//any time an Error case is found or malloc fails
//both stacks get freed and exit(1) to exit out of the program from anywhere
int	errorexit(t_data *data, int mode)
{
	if (mode >= 1)
		free(data->a);
	if (mode >= 2)
		free(data->b);
	write(2, "Error\n", 6);
	exit(1);
}

//go through the entire stack, return 1 incase of an error
//no leading zeros, multiple negative signs, non numbers
long	error_check_fillstack(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (i < ac)
	{
		j = -1;
		count = 0;
		if (av[i][0] == '0' && av[i][1] != '\0')
			return (1);
		while (av[i][++j])
		{
			if (av[i][j] == '-')
				count++;
			if (count >= 2)
				return (1);
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-'))
				return (1);
		}
		i++;
	}
	return (0);
}

//actually just stringlen with a check
//-2147483648 is 11 symbols and the max size
//because only integers are accepted
int	numlen_errorcheck(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (i > 11)
			return (-1);
		i++;
	}
	return (i);
}

//no duplicate numbers allowed
int	duplicatecheck(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->a[i] != data->end)
	{
		j = 0;
		while (j < data->argc)
		{
			if (data->a[i] == data->a[j] && (i != j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
