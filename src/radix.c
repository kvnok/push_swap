/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:35:21 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 21:06:15 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for max 32 bits worth of loops the entire stack gets traversed
// if the current bit is 1 the num stays else it gets thrown to B
// B in this case is all values with bit 0 on << j
// after alen looped the smaller bit values get push back to A
void	radix(t_data *data)
{
	int	i;
	int	j;
	int	alen;

	i = 0;
	j = 0;
	alen = arrlen(data);
	while (j < 32)
	{
		i = 0;
		while (i < alen)
		{
			if ((data->a[0] & (1u << j)) == 0)
				pb(data, 1);
			else
				ra(data, 1);
			i++;
		}
		move_all_to_a(data);
		if (is_a_sorted(data))
			break ;
		j++;
	}
}
// bit with value 1 on the most left side is the last that ends up below
// left most is the MSB, Most Significant Bit
// right most is the LSB, Least Significant Bit
