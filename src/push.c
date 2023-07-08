/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:10:26 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:38:12 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push first num from B to A
// if empty do nothing
// get the length of A
// move all of A down 1 to make space for the top of B
// move all of B up 1 to overwrite moved value and others
// make new end data->end
void	pa(t_data *data, int check)
{
	int	i;

	i = 0;
	if (check == 1)
	{
		ft_printf("pa\n");
		data->operationcounter++;
	}
	if (data->b[0] == data->end)
		return ;
	while (data->a[i] != data->end)
		i++;
	while (i)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = data->b[0];
	while (data->b[i + 1] != data->end)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[i] = data->end;
}

// push first num from A to B
// if empty do nothing
// get the length of B
// move all of B down 1 to make space for the top of A
// move all of A up 1 to overwrite moved value and others
// make new end data->end
void	pb(t_data *data, int check)
{
	int	i;

	i = 0;
	if (check == 1)
	{
		ft_printf("pb\n");
		data->operationcounter++;
	}
	if (data->a[0] == data->end)
		return ;
	while (data->b[i] != data->end)
		i++;
	while (i)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = data->a[0];
	while (data->a[i + 1] != data->end)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[i] = data->end;
}
