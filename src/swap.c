#include "../include/push_swap.h"

void	sa(t_head *a, t_head *b, int to_aff)
{
	t_stack	*old_first;
	t_stack	*last;

	(void)b;
	if (a->first == NULL || a->first->next == a->first)
		return ;
	last = a->first->before;
	old_first = a->first;
	a->first = a->first->next;
	last->next = a->first;
	a->first->before = last;
	old_first->next = a->first->next;
	a->first->next->before = old_first;
	a->first->next = old_first;
	old_first->before = a->first;
	old_first->index = 1;
	a->first->index = 0;
	if (to_aff)
		ft_printf("sa\n");
	//aff(a, b, 13);
}

void	sb(t_head *a, t_head *b, int to_aff)
{
	t_stack	*old_first;
	t_stack	*last;

	(void)a;
	if (a->first == NULL || a->first->next == a->first)
		return ;
	last = b->first->before;
	old_first = b->first;
	b->first = b->first->next;
	last->next = b->first;
	b->first->before = last;
	old_first->next = b->first->next;
	b->first->next->before = old_first;
	b->first->next = old_first;
	old_first->before = b->first;
	old_first->index = 1;
	a->first->index = 0;
	if (to_aff)
		ft_printf("sb\n");
	//aff(a, b, 13);
}

void	ss(t_head *a, t_head *b)
{
	sa(a, b, 0);
	sb(a, b, 0);
	ft_printf("ss\n");
	//aff(a, b, 13);
}
