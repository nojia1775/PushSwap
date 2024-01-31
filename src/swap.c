#include "../include/push_swap.h"

void	sa(t_head *a, t_head *b)
{
	t_stack	*tmp;
	t_stack	*last;

	(void)b;
	if (len(a) <= 1)
		return ;
	last = get_last(a);
	tmp = a->first;
	a->first = a->first->next;
	a->first->before = last;
	tmp->next = a->first->next;
	a->first->next->before = tmp;
	a->first->next = tmp;
	tmp->before = a->first;
	ft_printf("sa\n");
}

void	sb(t_head *a, t_head *b)
{
	t_stack	*tmp;
	t_stack	*last;

	(void)a;
	if (len(b) <= 1)
		return ;
	last = get_last(b);
	tmp = b->first;
	b->first = b->first->next;
	b->first->before = last;
	tmp->next = b->first->next;
	b->first->next->before = tmp;
	b->first->next = tmp;
	tmp->before = b->first;
	ft_printf("sb\n");
}
