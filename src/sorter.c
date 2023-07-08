/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorter.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 16:19:10 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 19:28:52 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//only 5 different possiblities
/*
0 2 1
1 0 2
2 0 1
1 2 0
2 1 0
*/
void	sort_three(t_data *data)
{
	if (is_a_sorted(data) == 1)
		return ;
	if (data->a[0] < data->a[1] && data->a[0] < data->a[2])
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (data->a[0] > data->a[1] && data->a[0] < data->a[2])
		sa(data, 1);
	else if (data->a[0] > data->a[1] && data->a[1] < data->a[2])
		ra(data, 1);
	else if (data->a[0] < data->a[1] && data->a[0] > data->a[2])
		rra(data, 1);
	else
	{
		sa(data, 1);
		rra(data, 1);
	}
}

//push lowest number to B
//then do sort_three
//throw lowest back on top of A
void	sort_four(t_data *data)
{
	smallest_to_top(data);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
}

//push lowest two numbers to B
//then do sort_three
//throw lowest back on top of A
void	sort_five(t_data *data)
{
	smallest_to_top(data);
	pb(data, 1);
	smallest_to_top(data);
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
	pa(data, 1);
}

//permutation with order mattering
//no repeating digits
//formula
//    n!
// --------
// (n - r)!
// but basicly just 4 * 3 * 2 * 1 = 24, 4! 
//cases for 2 - 5 numbers else just use radix
void	sorter(t_data *data)
{
	int	alen;
	int	i;

	alen = arrlen(data);
	i = 0;
	if (alen == 2)
		sa(data, 1);
	else if (alen == 3)
		sort_three(data);
	else if (alen == 4)
		sort_four(data);
	else if (alen == 5)
		sort_five(data);
	else
		radix(data);
}
