/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 16:35:04 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 17:51:30 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the stuff that cant fit in the while loop
void	binarystacks(t_data *data, int i, int len)
{
	int	templen;

	templen = len;
	if (data->a[i] != data->end)
	{
		while (templen >= 0)
		{
			if ((data->a[i] & (1u << templen)) != 0)
				ft_printf("1");
			else
				ft_printf("0");
			templen--;
		}
	}
	ft_printf("				");
	if (data->b[i] == data->end)
		return ;
	while (len >= 0)
	{
		if ((data->b[i] & (1u << len)) != 0)
			ft_printf("1");
		else
			ft_printf("0");
		len--;
	}	
}

//printing the stacks in binary instead of base 10 (decimal)
//if argc <= 6   : print 3 bits : for example 110
//if argc == 101 : print 7 bits : for example 0011010 
//if argc == 501 : print 9 bits : for example 100100110
void	printbinary(t_data *data)
{
	int	i;
	int	len;

	i = 31;
	len = data->argc - 1;
	while (i >= 0)
	{
		if ((len & (1u << i)) != 0)
			break ;
		i--;
	}
	len = i;
	i = 0;
	ft_printf("a				b\n");
	ft_printf("-----------------		-----------------\n");
	while (data->a[i] != data->end || data->b[i] != data->end)
	{
		binarystacks(data, i, len);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

//get the length of a number
int	numlen(int num)
{
	int	count;

	count = 0;
	if (num <= 0)
	{
		count++;
		num = num * -1;
	}
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

//using ft_printf which uses write, to get spacing correct
//can be used in main
//or in any function to check how the stacks are being updated
void	printstacks(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("a				b\n");
	ft_printf("-----------------		-----------------\n");
	while (data->a[i] != data->end || data->b[i] != data->end)
	{
		if (data->a[i] != data->end)
			ft_printf("%d		", (int)data->a[i]);
		else
			ft_printf("			");
		if (numlen(data->a[i]) <= 7)
			ft_printf("	");
		if (numlen(data->a[i]) <= 14)
			ft_printf("	");
		if (data->b[i] != data->end)
			ft_printf("%d	", (int)data->b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
