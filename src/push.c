#include "../include/push_swap.h"

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
	aff(a, b, 9);
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
	aff(a, b, 9);
}
