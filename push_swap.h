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

t_stack				*ft_stacklast(t_stack *lst);

#endif