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
void	sa(t_head *a, t_head *b);
void	sb(t_head *a, t_head *b);

struct	s_stack
{
	int	data;
	t_stack	*next;
	t_stack	*before;
};

struct	s_head
{
	t_stack	*first;
};

#endif
