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

// void	pb(t_head *a, t_head *b)
// {
// 	t_stack	*tmp;

// 	if (b->first == NULL)
// 		return ;
// 	tmp = a->first;
// 	b->first = a->first;
// 	a->first->before = 
// }

// void	pa(t_head*a, t_head *b)
// {
// 	t_stack	*tmp;

// 	if (a->first == NULL)
// 		return ;
// 	tmp = b->first;
// 	b->first = a->first;
// 	a->first->before->next = a->first->next;
// 	a->first->next->before = a->first->before;
// 	tmp->before->next = b->first;
// 	b->first->before = tmp->before;
// 	b->first->next = tmp;
// 	tmp->before = b->first;
// }


static void	add_front(int data, t_head *head)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = data;
	if (head->first == NULL)
	{
		head->first = new;
		new->next = new;
		new->before = new;
		new->target = NULL;
		new->index = 0;
	}
	else
	{
		new->next = head->first;
		new->before = head->first->before;
		head->first->before->next = new;
		head->first->before = new;
		head->first = new;
		new->target = NULL;
		upper_all(head);
		new->index = 0;
	}
}

void	pa(t_head *a, t_head *b)
{
	t_stack	*tmp;

	if (b->first == NULL)
		return ;
	add_front(b->first->data, a);
	tmp = b->first;
	if (tmp->next == tmp)
	{
		free(tmp);
		b->first = NULL;
	}
	else
	{
		b->first->before->next = b->first->next;
		b->first->next->before = b->first->before;
		b->first = b->first->next;
		free(tmp);
		lower_all(b);
	}
	ft_printf("pa\n");
	//aff(a, b, 13);
}

void	pb(t_head *a, t_head *b)
{
	t_stack	*tmp;

	if (a->first == NULL)
		return ;
	add_front(a->first->data, b);
	tmp = a->first;
	if (tmp->next == tmp)
	{
		free(tmp);
		a->first = NULL;
	}
	else
	{
		a->first->before->next = a->first->next;
		a->first->next->before = a->first->before;
		a->first = a->first->next;
		free(tmp);
		lower_all(a);
	}
	ft_printf("pb\n");
	//aff(a, b, 13);
}

