/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 18:02:47 by kkroon        #+#    #+#                 */
/*   Updated: 2023/03/12 18:13:20 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/src/libft.h"

typedef struct s_data
{
	long	*a;
	long	*b;
	long	end;
	int		argc;
	int		operationcounter;
}	t_data;

//errorcheck
int		errorexit(t_data *data, int mode);
long	error_check_fillstack(int ac, char **av);
int		duplicatecheck(t_data *data);
int		numlen_errorcheck(char *num);

//fillstack
void	longcalloc(t_data *data);
long	fillstack(int ac, char **av, t_data *data);
void	alloc_fill(int argc, char **argv, t_data *data);

//helpers
int		arrlen(t_data *data);
void	move_all_to_b(t_data *data);
void	move_all_to_a(t_data *data);
int		is_a_sorted(t_data *data);

//indexes
int		get_index(t_data *data, int n);
void	index_convert(t_data *data);

//printing
void	binarystacks(t_data *data, int i, int len);
void	printbinary(t_data *data);
int		numlen(int num);
void	printstacks(t_data *data);

//push
void	pa(t_data *data, int check);
void	pb(t_data *data, int check);

//radix
void	radix(t_data *data);

//reverse
void	rra(t_data *data, int check);
void	rrb(t_data *data, int check);
void	rrr(t_data *data, int check);

//rotate
void	ra(t_data *data, int check);
void	rb(t_data *data, int check);
void	rr(t_data *data, int check);

//sorter
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	sorter(t_data *data);

//support
int		choose_direction(t_data *data, int i);
int		find_smallest(t_data *data);
void	smallest_to_top(t_data *data);

//swap
void	sa(t_data *data, int check);
void	sb(t_data *data, int check);
void	ss(t_data *data, int check);

#endif
