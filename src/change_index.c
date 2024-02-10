/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:06:49 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/10 15:30:23 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lower_all(t_head *head)
{
	t_stack	*cur;

	cur = head->first;
	while (1)
	{
		cur->index -= 1;
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
}

void	upper_all(t_head *head)
{
	t_stack	*cur;

	cur = head->first;
	while (1)
	{
		cur->index += 1;
		cur = cur->next;
		if (cur == head->first)
			break ;
	}
}
