/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillstack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:34:43 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:19:48 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//allocate space for long sized numbers
//the arrays are basicly like \0 terminated strings
//only the terminatation is data->end 9876543210123456789
void	longcalloc(t_data *data)
{
	int	i;

	i = 0;
	data->a = malloc(data->argc * sizeof(long));
	if (data->a == NULL)
		errorexit(data, 1);
	data->b = malloc(data->argc * sizeof(long));
	if (data->b == NULL)
		errorexit(data, 2);
	while (i < data->argc)
	{
		data->a[i] = data->end;
		data->b[i] = data->end;
		i++;
	}
}

// fill the stack and return the errorcheck
// j = -1 to fit within 25 lines
// ++j is increment then check, so av[i][++j] is av[i][0] on first check
long	fillstack(int ac, char **av, t_data *data)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	num = 0;
	while (i < ac)
	{
		j = -1;
		if (numlen_errorcheck(av[i]) == -1)
			return (1);
		if (av[i][0] == '-')
			j++;
		while (av[i][++j])
			num = (num * 10) + (av[i][j] - '0');
		if (av[i][0] == '-')
			num = num * -1;
		if (num > 2147483647 || num < -2147483648)
			return (1);
		data->a[i - 1] = num;
		num = 0;
		i++;
	}
	return (error_check_fillstack(ac, av));
}

//calloc with long numbers
//if the input is incorrect in any way the functions return 1
//if the fill, errorcheck, duplicatecheck return 1, errorexit(data, 2) is called
void	alloc_fill(int argc, char **argv, t_data *data)
{
	longcalloc(data);
	if (fillstack(argc, argv, data))
		errorexit(data, 2);
	if (duplicatecheck(data))
		errorexit(data, 2);
}
