/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 13:20:14 by kkroon        #+#    #+#                 */
/*   Updated: 2023/02/04 17:17:06 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	checker(char symbol, va_list args, int *result);
void	case_percent(int *result);
void	case_bigx(va_list args, int *result, char *uhex);
void	case_smallx(va_list args, int *result, char *lhex);
void	case_u(va_list args, int *result);
void	case_d_or_i(va_list args, int *result);
void	case_p(va_list args, int *result, char *lhex);
void	case_s(va_list args, int *result);
void	case_c(va_list args, int *result);
void	case_null(int *result);
void	print_upper_hex(unsigned long num, int *result, char *uhex);
void	print_lower_hex(unsigned long num, int *result, char *lhex);
void	print_unsigned(unsigned int n, int *result);
void	print_signed(int n, int *result);
int		mystrlen(const char *s);
char	*mystrcpy(char *dst, char *src);
void	write_and_increment(int *result, char letter);

#endif