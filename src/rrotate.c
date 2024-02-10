/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:08:32 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/10 15:08:33 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_head *a, t_head *b, int to_aff)
{
	(void)b;
	if (a->first == NULL || a->first->next == a->first)
		return ;
	a->first = a->first->before;
	upper_all(a);
	a->first->index = 0;
	if (to_aff)
		ft_printf("rra\n");
}

void	rrb(t_head *a, t_head *b, int to_aff)
{
	(void)a;
	if (b->first == NULL || b->first->next == b->first)
		return ;
	b->first = b->first->before;
	upper_all(b);
	b->first->index = 0;
	if (to_aff)
		ft_printf("rrb\n");
}

void	rrr(t_head *a, t_head *b)
{
	rra(a, b, 0);
	rrb(a, b, 0);
	ft_printf("rrr\n");
}
