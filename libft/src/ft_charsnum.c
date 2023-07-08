/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charsnum.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:35:12 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/16 08:37:36 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_null(int *result)
{
	(*result) += 6;
	write(1, "(null)", 6);
}

void	case_c(va_list args, int *result)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*result)++;
}

void	case_s(va_list args, int *result)
{
	char	*string;
	int		i;

	string = va_arg(args, char *);
	i = 0;
	if (!string)
		case_null(result);
	else
	{
		while (string[i])
		{
			write(1, &string[i], 1);
			(*result)++;
			i++;
		}
	}
}

void	case_d_or_i(va_list args, int *result)
{
	int	d_or_i;

	d_or_i = va_arg(args, int);
	if (!d_or_i)
	{
		write(1, "0", 1);
		(*result)++;
	}
	else
		print_signed(d_or_i, result);
}

void	case_u(va_list args, int *result)
{
	unsigned int	unsigned_decimal;

	unsigned_decimal = va_arg(args, unsigned int);
	if (!unsigned_decimal)
	{
		write(1, "0", 1);
		(*result)++;
	}
	else
		print_unsigned(unsigned_decimal, result);
}
