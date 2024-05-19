/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:28:57 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/11 18:41:23 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed(int n, int *result)
{
	char			c;
	long long int	ncpy;

	ncpy = n;
	if (ncpy < 0)
	{
		ncpy = ncpy * -1;
		write(1, "-", 1);
		(*result)++;
	}
	if (ncpy > 9)
		print_signed(ncpy / 10, result);
	c = (ncpy % 10) + '0';
	write(1, &c, 1);
	(*result)++;
}

void	print_unsigned(unsigned int n, int *result)
{
	char	c;

	if (n > 9)
		print_signed(n / 10, result);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*result)++;
}

void	print_lower_hex(unsigned long num, int *result, char *lhex)
{
	char	c;

	if (num > 15)
		print_lower_hex(num / 16, result, lhex);
	(*result)++;
	c = lhex[num % 16];
	write(1, &c, 1);
}

void	print_upper_hex(unsigned long num, int *result, char *uhex)
{
	char	c;

	if (num > 15)
		print_upper_hex(num / 16, result, uhex);
	(*result)++;
	c = uhex[num % 16];
	write(1, &c, 1);
}
