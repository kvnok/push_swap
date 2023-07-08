/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:13:30 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/11 19:21:18 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the matching number
//and return the index where it should be if the numbers are sorted
int	get_index(t_data *data, int n)
{
	int	indexcounter;
	int	i;

	indexcounter = 0;
	i = 0;
	while (data->a[i] != data->end)
	{
		if (data->a[i] < n)
			indexcounter++;
		i++;
	}
	return (indexcounter);
}

//seperate array with index
//after loop is done overwrite data->a[i]
void	index_convert(t_data *data)
{
	int	i;
	int	*indexes;

	i = 0;
	while (data->a[i] != data->end)
	{
		i++;
	}
	indexes = malloc(sizeof(long) * (i + 1));
	if (indexes == NULL)
		errorexit(data, 2);
	i = 0;
	while (data->a[i] != data->end)
	{
		indexes[i] = get_index(data, data->a[i]);
		i++;
	}	
	i = 0;
	while (data->a[i] != data->end)
	{
		data->a[i] = indexes[i];
		i++;
	}
	free(indexes);
}
