/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/06 18:38:59 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/16 08:56:04 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mystrcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	mystrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	checker(char symbol, va_list args, int *result)
{
	char	*lhex;
	char	*uhex;

	lhex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	if (symbol == 'c')
		case_c(args, result);
	else if (symbol == 's')
		case_s(args, result);
	else if (symbol == 'p')
		case_p(args, result, lhex);
	else if (symbol == 'd' || symbol == 'i')
		case_d_or_i(args, result);
	else if (symbol == 'u')
		case_u(args, result);
	else if (symbol == 'x')
		case_smallx(args, result, lhex);
	else if (symbol == 'X')
		case_bigx(args, result, uhex);
	else if (symbol == '%')
		case_percent(result);
}

void	write_and_increment(int *result, char letter)
{
	write(1, &letter, 1);
	(*result)++;
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		srclen;
	int		result;
	va_list	args;

	i = 0;
	srclen = mystrlen(s);
	result = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			write_and_increment(&result, s[i]);
		if (s[i] == '%' && i < srclen)
		{
			if (s[i + 1] == '\0')
				break ;
			checker(s[i + 1], args, &result);
			i++;
		}
		i++;
	}
	va_end(args);
	return (result);
}
