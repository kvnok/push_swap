/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexetc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 14:35:09 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/11 18:41:55 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_p(va_list args, int *result, char *lhex)
{
	void	*num;

	num = va_arg(args, void *);
	write(1, "0x", 2);
	(*result)++;
	(*result)++;
	print_lower_hex((unsigned long)num, result, lhex);
}

void	case_smallx(va_list args, int *result, char *lhex)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	print_lower_hex(num, result, lhex);
}

void	case_bigx(va_list args, int *result, char *uhex)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	print_upper_hex(num, result, uhex);
}

void	case_percent(int *result)
{
	write(1, "%%", 1);
	(*result)++;
}
