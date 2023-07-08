/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:10:42 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:34:07 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// move all numbers up one, first num becomes last num. in A
void	ra(t_data *data, int check)
{
	int	temp;
	int	i;

	if (check == 1)
	{
		ft_printf("ra\n");
		data->operationcounter++;
	}
	if (data->a[1] == data->end)
		return ;
	i = 0;
	temp = data->a[0];
	while (data->a[i + 1] != data->end)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[i] = temp;
}

// move all numbers up one, first num becomes last num. in B
void	rb(t_data *data, int check)
{
	int	temp;
	int	i;

	if (check == 1)
	{
		ft_printf("rb\n");
		data->operationcounter++;
	}
	if (data->b[1] == data->end)
		return ;
	i = 0;
	temp = data->b[0];
	while (data->b[i + 1] != data->end)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[i] = temp;
}

// move all numbers up one, first num becomes last num. in A and B
void	rr(t_data *data, int check)
{
	if (check == 1)
	{
		ft_printf("rr\n");
		data->operationcounter++;
	}
	ra(data, 0);
	rb(data, 0);
}
