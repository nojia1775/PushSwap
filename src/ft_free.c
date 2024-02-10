/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:07:31 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/10 15:07:51 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rm(t_head *head, int size)
{
	t_stack	*rm;
	t_stack	*cur;
	int		i;

	if (head->first != NULL)
		cur = head->first;
	i = 0;
	while (i++ < size)
	{
		rm = cur;
		cur = cur->next;
		free(rm);
	}
}

void	ft_free(t_head *a, t_head *b)
{
	int	size;

	size = len(a);
	rm(a, size);
	size = len(b);
	rm(b, size);
	free(a);
	free(b);
}
