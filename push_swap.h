#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structs */
typedef struct s_stack
{
	int				content;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef enum e_flags
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
	ERROR
}					t_flags;

typedef struct s_info
{
	int				bench;
	int				skip_position;
	t_flags			flags;
	float			disorder;
	int				size;
}					t_info;

/* Stack utils */
t_stack				*ft_stacknew(int content);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack);
t_stack				*ft_min(t_stack *a);
t_stack				*ft_max(t_stack *a);
int					ft_stacksize(t_stack *stack);
void				ft_stack_clear(t_stack **stack);
void				ft_print_stack(t_stack **stack);

/* Operations */
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				orchestrator(t_stack **a, t_stack **b, t_info *info);
int					parsing(t_info *info, char **argv);

/* Utils */
int					ft_atoi(const char *nptr);
int					validate_dupes(char **argv);
int					ft_is_not_int(char *argv);
float				disorder(int *stack, int size);
int					ft_strcmp(char *s1, char *s2);
int					flags_validator(t_info *info, char **argv);

/* Sort_5 */

void				rotmin(t_stack **a, int size);
void				rotmax(t_stack **a, int size);
void				sort_3(t_stack **a);
void				sort_5(t_stack **a, t_stack **b, int size);

/* Insertion algorithm */
int					ft_rotations_cost(t_stack *b, int value);
int					ft_cost_in_a(t_stack *a, int value, int size);
int					find_cheapest(t_stack **a, t_stack **b, int size);
void				rotate_a_to_position(t_stack **a, int position, int size);
void				rotate_b_to_position(t_stack **b, int rotations, int size);
void				insertion(t_stack **a, t_stack **b, int size);

/* Main Utils */

t_stack				*stack_creator(int *array, int size);
int					*array_creator(int argc, char **argv);

#endif