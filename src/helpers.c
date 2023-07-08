/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:38:52 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 18:12:43 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//basicly same as stringlen
int	arrlen(t_data *data)
{
	int	i;

	i = 0;
	while (data->a[i] != data->end)
		i++;
	return (i);
}

//empty out the A stack into B
void	move_all_to_b(t_data *data)
{
	while (data->a[0] != data->end)
	{
		pb(data, 1);
	}
}

//empty out the B stack into A
void	move_all_to_a(t_data *data)
{
	while (data->b[0] != data->end)
	{
		pa(data, 1);
	}
}

//if the current num is always lower then the next, the stack is sorted
int	is_a_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (data->a[i] != data->end)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
