/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:10:44 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/09 11:10:45 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	empty(t_head *dest, t_head *src)
{
	if (src->first->next != src->first)
	{
		dest->first = src->first;
		src->first->before->next = src->first->next;
		src->first->next->before = src->first->before;
		src->first = src->first->next;
		dest->first->next = dest->first;
		dest->first->before = dest->first;
		lower_all(src);
	}
	else
	{
		dest->first = src->first;
		dest->first->next = dest->first;
		dest->first->before = dest->first;
		src->first = NULL;
	}
}

static void	not_empty(t_head *dest, t_head *src)
{
	t_stack	*tmp;

	if (src->first->next != src->first)
	{
		tmp = dest->first;
		dest->first = src->first;
		src->first->next->before = src->first->before;
		src->first->before->next = src->first->next;
		src->first = src->first->next;
		dest->first->next = tmp;
		dest->first->before = tmp->before;
		tmp->before->next = dest->first;
		tmp->before = dest->first;
		lower_all(src);
	}
	else
	{
		tmp = dest->first;
		dest->first = src->first;
		src->first = NULL;
		dest->first->next = tmp;
		dest->first->before = tmp->before;
		tmp->before->next = dest->first;
		tmp->before = dest->first;
	}
}

 void	pa(t_head *a, t_head *b)
 {
	t_stack	*cur;

 	if (b->first == NULL)
 		return ;
	if (!a->first)
		empty(a, b);
	else
		not_empty(a, b);
	a->first->index = 0;
	cur = a->first->next;
	while (1)
	{
		if (cur == a->first)
			break ;
		cur->index++;
		cur = cur->next;
	}
	ft_printf("pa\n");
 }

 void	pb(t_head *a, t_head *b)
 {
	t_stack	*cur;

 	if (a->first == NULL)
 		return ;
	if (!b->first)
		empty(b, a);
	else
		not_empty(b, a);
	b->first->index = 0;
	cur = b->first->next;
	while (1)
	{
		if (cur == b->first)
			break ;
		cur->index++;
		cur = cur->next;
	}
	ft_printf("pb\n");
 }