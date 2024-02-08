/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:10:58 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/08 17:14:07 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*little(t_head *head)
{
	t_stack	*cur;
	t_stack	*add;
	int		tmp;

	cur = head->first;
	tmp = cur->data;
	add = cur;
	while (1)
	{
		if (cur->data < tmp)
		{
			tmp = cur->data;
			add = cur;
		}
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
	return (add);
}	

void	calibrage(t_head *a, t_head *b)
{
	t_stack	*cur;
	int		i;

	i = 0;
	cur = little(a);
	if (cur->index >= a->first->before->index + 1 / 2)
		while (cur->index != 0)
			rra(a, b, 1);
	else
		while (cur->index != 0)
			ra(a, b, 1);
}
