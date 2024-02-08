/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:34:45 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 10:05:03 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_head *a, t_head *b, int to_aff)
{
	(void)b;
	if (a->first == NULL || a->first->next == a->first)
		return ;
	a->first = a->first->next;
	lower_all(a);
	a->first->before->index = a->first->before->before->index + 1;
	if (to_aff)
		ft_printf("ra\n");
	aff(a, b, 9);
}

void	rb(t_head *a, t_head *b, int to_aff)
{
	(void)a;
	if (b->first == NULL || b->first->next == a->first)
		return ;
	b->first = b->first->next;
	lower_all(b);
	b->first->before->index = b->first->before->before->index + 1;
	if (to_aff)
		ft_printf("rb\n");
	aff(a, b, 9);
}

void	rr(t_head *a, t_head *b)
{
	ra(a, b, 0);
	rb(a, b, 0);
	ft_printf("rr\n");
	aff(a, b, 9);
}
