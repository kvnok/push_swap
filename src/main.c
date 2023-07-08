/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 10:45:02 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 19:29:20 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// always test in bash just like the subject
// every function has a check to make them print or not
// only on 0 if using the function indirectly
int	main(int argc, char **argv)
{
	t_data	data;

	data.end = 98765432123456789;
	data.argc = argc;
	data.operationcounter = 0;
	if (argc == 1)
		exit(1);
	alloc_fill(argc, argv, &data);
	if (arrlen(&data) < 1)
		errorexit(&data, 2);
	if (is_a_sorted(&data))
	{
		free(data.a);
		free(data.b);
		return (0);
	}
	index_convert(&data);
	sorter(&data);
	free(data.a);
	free(data.b);
	return (0);
}
/*
// printstacks(&data);
// printbinary(&data);
// ft_printf("operations done: %d\n", data.operationcounter);
// printstacks(&data);
*/
