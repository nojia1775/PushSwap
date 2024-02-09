/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:36:01 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 10:09:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost(t_stack *stack, t_head *a, t_head *b)
{
	int	costa;
	int	costb;
	int	same;

	same = 0;
	if (stack->index == 0 && stack->target->index == 0)
		return (1);
	if (stack->index > a->first->before->index / 2 + 1)
		costa = ft_abs(stack->index - a->first->before->index + 1);
	else
	{
		costa = stack->index;
		same = 1;
	}
	if (stack->target->index > b->first->before->index / 2 + 1)
	{
		costb = ft_abs(stack->target->index
			- b->first->before->index + 1);
		same = 0;
	}
	else
		costb = stack->target->index;
	if (!same)
		return (costa + costb + 1);
	return (thelow(costa, costb) + ft_abs(costa - costb) + 1);
}

static int	targeting(t_stack *cura, t_stack *curb, t_head *b)
{
	if (isthelil(cura, b))
		return (1);
	if (cura->target == NULL)
	{
		if (cura->data > curb->data)
			cura->target = curb;
	}
	if (cura->target != NULL)
	{
		if (cura->data > curb->data)
		{
			if (ft_abs(cura->data - cura->target->data)
			> ft_abs(cura->data - curb->data))
				cura->target = curb;
			else if (cura->data < cura->target->data)
				cura->target = curb;
		}
	}
	return (0);	
}

void	target(t_head *a, t_head *b)
{
	t_stack	*cura;
	t_stack	*curb;

	cura = a->first;
	curb = b->first;
	while (1)
	{
		while (1)
		{
			if (targeting(cura, curb, b))
				break ;
			curb = curb->next;
			if (curb == b->first)
				break ;
		}
		cura = cura->next;
		if (cura == a->first)
			break ;
	}
}

static void	algo2a(t_head *a, t_head *b)
{
	t_stack	*cur;
	t_cost	prix;

	prix.cout = 0;
	prix.elem = NULL;
	cur = a->first;
	while (a->first->before->index != 2)
	{
		//ft_printf("OOOOOOOOOOOOOOOO %d", prix.elem->data);
		if (cost(cur, a, b) == 1)
		{
			pb(a, b);
			cur = a->first;
			target(a, b);
		}
		else

			expa(&prix, &cur, a, b);
	}
}

void	algo(t_head *a, t_head *b)
{
	trois(a, b);
	issort(a, b);
	pb(a, b);
	if (a->first->before->index > 3)
	{
		pb(a, b);
		target(a, b);
		algo2a(a, b);
	}
	else if (a->first->before->index == 3)
		pb(a, b);
	if (a->first->before->index == 2)
		trois(a, b);
	targetb(b, a);
	algo2b(b, a);
	calibrage(a, b);
}
