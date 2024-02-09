/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:03:18 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 15:34:22 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	isthebig(t_stack *stack, t_head *head)
{
	t_stack	*cur;
	t_stack	*tmp;
	int		lil;

	lil = head->first->data;
	cur = head->first;
	tmp = head->first;
	while (1)
	{
		if (cur->data > stack->data)
			return (0);
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
	while (1)
	{
		cur = cur->next;
		if (cur->data < lil)
		{
			lil = cur->data;
			tmp = cur;
		}
		if (cur == head->first)
			break ;
	}
	stack->target = tmp;
	return (1);
}

int	costb(t_stack *stack, t_head *a, t_head *b)
{
	int	costa;
	int	costb;
	int	same;

	(void)a;
	same = 0;
	if (stack->index == 0 && stack->target->index == 0)
		return (1);
	if (stack->index > b->first->before->index / 2 + 1)
		costa = ft_abs(stack->index - b->first->before->index + 1);
	else
	{
		costa = stack->index;
		same = 1;
	}
	if (stack->target->index > a->first->before->index / 2 + 1)
	{
		costb = ft_abs(stack->target->index
			- a->first->before->index + 1);
		same = 0;
	}
	else
		costb = stack->target->index;
	if (!same)
		return (costa + costb + 1);
	return (thelow(costa, costb) + ft_abs(costa - costb) + 1);
}

void	add_to_list(char ***params, t_head *a)
{
	int	i;
	int	j;

	i = 0;
	while (params[i])
	{
		j = 0;
		while (params[i][j])
			add_list(ft_atoi(params[i][j++]), a);
		i++;
	}
}
