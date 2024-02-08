/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:43:53 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 09:45:49 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sameposb(t_head *b, t_head *a, int *mov, t_cost *prix)
{
	int	i;
	
	i = 0;
	while (i++ < thelow(mov[0], mov[1]))
		rr(a, b);
	if (prix->elem->index == 0 && prix->elem->target->index == 0)
		pa(a, b);
	else
	{
		i = 0;
		while (i++ < ft_abs(prix->elem->index - prix->elem->target->index))
		{
			if (prix->elem->index != 0)
				rb(a, b, 1);
			else
				ra(a, b, 1);
		}
		pa(a, b);
	}
}

static void	samenegb(t_head *b, t_head *a, int *mov, t_cost *prix)
{
	int	i;

	i = 0;
	while (i-- > thelow(mov[0], mov[1]))
		rrr(a, b);
	if (prix->elem->index == 0 && prix->elem->target->index == 0)
		pa(a, b);
	else
	{
		i = 0;
		while (i++ < ft_abs(prix->elem->index - prix->elem->target->index))
		{
			if (prix->elem->index != 0)
				rrb(a, b, 1);
			else
				rra(a, b, 1);
		}
		pa(a, b);
	}
}

static void	difb(t_head *b, t_head *a, int *mov)
{
	int	i;

	i = 0;
	while (i++ < ft_abs(mov[0]))
	{
		if (mov[0] < 0)
			rrb(a, b, 1);
		else
			rb(a, b, 1);
	}
	i = 0;
	while (i++ < ft_abs(mov[1]))
	{
		if (mov[1] < 0)
			rra(a, b, 1);
		else
			ra(a, b, 1);
	}
	pa(a, b);
}

void	depb(t_head *b, t_head *a, t_cost *prix)
{
	int	mov[2];

	if (prix->elem->index >= b->first->before->index / 2 + 1)
		mov[0] = -ft_abs(prix->elem->index - b->first->before->index)
			- 1;
	else
		mov[0] = prix->elem->index;
	if (prix->elem->target->index >= a->first->before->index / 2 + 1)
		mov[1] = -ft_abs(prix->elem->target->index
			- a->first->before->index) - 1;
	else
		mov[1] = prix->elem->target->index;
	if (mov[0] > 0 && mov[1] > 0)
		sameposb(b, a, mov, prix);
	else if (mov[0] < 0 && mov[1] < 0)
		samenegb(b, a, mov, prix);
	else
		difb(b, a, mov);
}
