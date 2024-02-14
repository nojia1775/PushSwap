/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:36:11 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/10 15:36:13 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	targetingb(t_stack *curb, t_stack *cura, t_head *a)
{
	if (isthebig(curb, a))
		return (1);
	if (curb->target == NULL)
	{
		if (curb->data < cura->data)
			curb->target = cura;
	}
	if (curb->target != NULL)
	{
		if (curb->data < cura->data)
		{
			if (ft_abs(curb->data - curb->target->data)
				> ft_abs(curb->data - cura->data))
				curb->target = cura;
			else if (curb->data > curb->target->data)
				curb->target = cura;
		}
	}
	return (0);
}

void	targetb(t_head *b, t_head *a)
{
	t_stack	*cura;
	t_stack	*curb;

	if (b->first == NULL)
		return ;
	cura = a->first;
	curb = b->first;
	while (1)
	{
		while (1)
		{
			if (targetingb(curb, cura, a))
				break ;
			cura = cura->next;
			if (cura == a->first)
				break ;
		}
		curb = curb->next;
		if (curb == b->first)
			break ;
	}
}

void	algo2b(t_head *b, t_head *a)
{
	t_stack	*cur;
	t_cost	prix;

	prix.cout = 0;
	cur = b->first;
	while (b->first != NULL)
	{
		if (costb(cur, b, a) == 1)
		{
			pa(a, b);
			if (b->first != NULL)
			{
				cur = b->first;
				targetb(b, a);
			}
		}
		else
		{
			expb(&prix, &cur, a, b);
			// if (b->first != NULL)
			// {
			// 	cur = b->first;
			// 	targetb(b, a);
			// }
		}
	}
}
