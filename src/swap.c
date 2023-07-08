/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:03:23 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:34:40 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// switch first two numbers in A
void	sa(t_data *data, int check)
{
	int	temp;

	if (check == 1)
	{
		ft_printf("sa\n");
		data->operationcounter++;
	}
	if (data->a[1] == data->end)
		return ;
	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
}

// switch first two numbers in B
void	sb(t_data *data, int check)
{
	int	temp;

	if (check == 1)
	{
		ft_printf("sb\n");
		data->operationcounter++;
	}
	if (data->b[1] == data->end)
		return ;
	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
}

// switch first two numbers in A and B
void	ss(t_data *data, int check)
{
	if (check == 1)
	{
		ft_printf("ss\n");
		data->operationcounter++;
	}
	sa(data, 0);
	sb(data, 0);
}
