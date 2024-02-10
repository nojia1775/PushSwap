/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trois.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:08:52 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/10 15:38:07 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	si(t_head *a, t_head *b, t_trois t)
{
	if (t.un < t.deux && t.un < t.trois && t.deux > t.trois)
	{
		rra(a, b, 1);
		sa(a, b, 1);
	}
	else if (t.un > t.deux && t.deux > t.trois)
	{
		sa(a, b, 1);
		rra(a, b, 1);
	}
	else if (t.un > t.deux && t.un < t.trois)
		sa(a, b, 1);
	else if (t.un < t.deux && t.un > t.trois)
		rra(a, b, 1);
	else if (t.un > t.deux && t.un > t.trois && t.deux < t.trois)
		ra(a, b, 1);
}

void	trois(t_head *a, t_head *b)
{
	t_trois	elems;

	if (a->first->before->index > 2)
		return ;
	elems.un = a->first->data;
	elems.deux = a->first->next->data;
	elems.trois = a->first->next->next->data;
	si(a, b, elems);
	a->first->target = NULL;
	a->first->next->target = NULL;
	a->first->next->next->target = NULL;
}
