/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:03:18 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/06 16:17:20 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	isthebig(t_stack *stack, t_head *head)
{
	t_stack	*cur;
	int		lil;

	lil = head->first->data;
	cur = head->first;
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
			lil = cur->data;
		if (cur == head->first)
			break ;
	}
	stack->target = cur;
	return (1);
}
