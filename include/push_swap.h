/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:36:46 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 15:31:53 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define SIZE 4
# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"

typedef struct s_stack	t_stack;
typedef struct s_head	t_head;
typedef struct s_cost	t_cost;

int		verif_param(char ***params);
void	aff(t_head *a, t_head *b, int size);
void	add_list(int data, t_head *head);
void	ft_free(t_head *a, t_head *b);
int		len(t_head *head);
t_stack	*get_last(t_head *head);
void	pa(t_head *a, t_head *b);
void	pb(t_head *a, t_head *b);
void	sa(t_head *a, t_head *b, int to_aff);
void	sb(t_head *a, t_head *b, int to_aff);
void	ss(t_head *a, t_head *b);
void	ra(t_head *a, t_head *b, int to_aff);
void	rb(t_head *a, t_head *b, int to_aff);
void	rr(t_head *a, t_head *b);
void	rra(t_head *a, t_head *b, int to_aff);
void	rrb(t_head *a, t_head *b, int to_aff);
void	rrr(t_head *a, t_head *b);
int		until_first(t_head *head, t_stack *new);
void	lower_all(t_head *head);
void	upper_all(t_head *head);
void	algo(t_head *a, t_head *b);
int		ft_abs(int n);
int		isthelil(t_stack *stack, t_head *head);
int		thelow(int a, int b);
void	issort(t_head *a, t_head *b);
void	trois(t_head *a, t_head *b);
void	dep(t_head *a, t_head *b, t_cost *prix);
void	algo2b(t_head *b, t_head *a);
int		cost(t_stack *stack, t_head *a, t_head *b);
void	target(t_head *a, t_head *b);
void	targetb(t_head *b, t_head *a);
int		isthebig(t_stack *stack, t_head *head);
void	depb(t_head *b, t_head *a, t_cost *prix);
void	expb(t_cost *prix, t_stack **cur, t_head *a, t_head *b);
void	expa(t_cost *prix, t_stack **cur, t_head *a, t_head *b);
void	calibrage(t_head *a, t_head *b);
int		costb(t_stack *stack, t_head *a, t_head *b);
void	add_to_list(char ***params, t_head *a);

struct	s_cost
{
	int		cout;
	t_stack	*elem;
};

struct	s_stack
{
	int	data;
	int	index;
	t_stack	*target;
	t_stack	*next;
	t_stack	*before;
};

struct	s_head
{
	t_stack	*first;
};

#endif
