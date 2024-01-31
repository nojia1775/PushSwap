#include "../include/push_swap.h"

t_stack	*get_last(t_head *head)
{
	t_stack	*cur;

	if (head->first == NULL)
		return (NULL);
	cur = head->first;
	while (cur->next != head->first)
		cur = cur->next;
	return (cur);
}

void	add_list(int data, t_head *head)
{
	t_stack	*new;
	t_stack	*last;
	
	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = data;
	last = get_last(head);
	if (!last)
	{
		head->first = new;
		new->next = new;
		new->before = new;
	}
	else
	{
		last->next = new;
		new->next = head->first;
		new->before = last;
		head->first->before = new;
	}
}
