/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   support.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 17:17:49 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 17:52:59 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra is rotate up
//rra is rotate down
//return 0 if rotating up is faster
//return 1 if rotating down is faster
int	choose_direction(t_data *data, int i)
{
	int	j;

	j = i;
	while (data->a[j] != data->end)
		j++;
	j = j - i;
	if (j < i)
		return (1);
	return (0);
}

//loop through A
//return index of the smallest number in A
int	find_smallest(t_data *data)
{
	int	i;
	int	temp;
	int	spot;

	i = 0;
	temp = data->a[0];
	spot = 0;
	while (data->a[i] != data->end)
	{
		if (data->a[i] < temp)
		{
			temp = data->a[i];
			spot = i;
		}
		i++;
	}
	return (spot);
}

//look up where the smallest is
//pass index to function choose_direction()
//rotate up or down depending on return
void	smallest_to_top(t_data *data)
{
	int	smallest_index;
	int	direction;

	smallest_index = find_smallest(data);
	direction = choose_direction(data, smallest_index);
	while (smallest_index != 0)
	{
		if (direction)
		{
			smallest_index++;
			if (data->a[smallest_index] == data->end)
				smallest_index = 0;
			rra(data, 1);
		}
		else
		{
			smallest_index--;
			ra(data, 1);
		}
	}
}
