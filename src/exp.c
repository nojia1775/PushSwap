/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:35:55 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 09:32:59 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	expb(t_cost *prix, t_stack **cur, t_head *a, t_head *b)
{
	if (prix->cout == 0 || costb(*cur, a, b) < prix->cout)
	{
		prix->cout = costb(*cur, a, b);
		prix->elem = *cur;
	}
	*cur = (*cur)->next;
	if (*cur == b->first)
	{
		targetb(b, a);
		depb(b, a, prix);
		prix->cout = 0;
		prix->elem = NULL;
		*cur = b->first;
	}
}

void	expa(t_cost *prix, t_stack **cur, t_head *a, t_head *b)
{
	if (prix->cout == 0 || cost(*cur, a, b) < prix->cout)
	{
		prix->cout = cost(*cur, a, b);
		prix->elem = *cur;
	}
	*cur = (*cur)->next;
	if (*cur == a->first)
	{
		target(a, b);
		dep(a, b, prix);
		prix->cout = 0;
		prix->elem = NULL;
		*cur = a->first;
	}
}
