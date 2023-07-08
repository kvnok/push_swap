/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:10:47 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:33:42 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move all numbers down one, last num becomes first num. in A
void	rra(t_data *data, int check)
{
	int	temp;
	int	i;

	if (check == 1)
	{
		ft_printf("rra\n");
		data->operationcounter++;
	}
	if (data->a[1] == data->end)
		return ;
	i = 0;
	while (data->a[i + 1] != data->end)
		i++;
	temp = data->a[i];
	while (i)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[i] = temp;
}

// move all numbers down one, last num becomes first num. in B
void	rrb(t_data *data, int check)
{
	int	temp;
	int	i;

	if (check == 1)
	{
		ft_printf("rrb\n");
		data->operationcounter++;
	}
	if (data->b[1] == data->end)
		return ;
	i = 0;
	while (data->b[i + 1] != data->end)
		i++;
	temp = data->b[i];
	while (i)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[i] = temp;
}

// move all numbers down one, last num becomes first num. in A and B
void	rrr(t_data *data, int check)
{
	if (check == 1)
	{
		ft_printf("rrr\n");
		data->operationcounter++;
	}
	rra(data, 0);
	rrb(data, 0);
}
