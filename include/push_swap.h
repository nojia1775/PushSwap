#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"

typedef struct s_stack	t_stack;
typedef struct s_head	t_head;

int		verif_param(char **argv);
void	aff(t_head *a, t_head *b, int size);
void	add_list(int data, t_head *head);
void	ft_free(t_head *a, t_head *b);
int		len(t_head *head);
t_stack	*get_last(t_head *head);
void	pa(t_head *a, t_head *b);
void	pb(t_head *a, t_head *b);
void	sa(t_head *a, t_head *b, int to_aff);
void	sb(t_head *a, t_head *b, int to_aff);
void	ss(t_head *a, t_head *b);
void	ra(t_head *a, t_head *b, int to_aff);
void	rb(t_head *a, t_head *b, int to_aff);
void	rr(t_head *a, t_head *b);
void	rra(t_head *a, t_head *b, int to_aff);
void	rrb(t_head *a, t_head *b, int to_aff);
void	rrr(t_head *a, t_head *b);
int		until_first(t_head *head, t_stack *new);
void	lower_all(t_head *head);
void	upper_all(t_head *head);
void	algo(t_head *a, t_head *b);
unsigned int		ft_abs(int n);
int		isthelil(t_stack *stack, t_head *head);
int		thelow(int a, int b);
void	issort(t_head *a, t_head *b);
void	trois(t_head *a, t_head *b);

struct	s_stack
{
	int	data;
	int	index;
	t_stack	*target;
	t_stack	*next;
	t_stack	*before;
};

struct	s_head
{
	t_stack	*first;
};

#endif
