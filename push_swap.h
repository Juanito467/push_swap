#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_values
{
	int				size;
}					t_values;

int	ft_lstsize(t_stack *lst);
t_stack	*ft_min(t_stack **a);
t_stack	*ft_max(t_stack **a);
int					ft_atoi(const char *nptr);
t_stack	**stack_creator(int *array, int size);
t_stack				*ft_stacklast(t_stack *lst);

#endif