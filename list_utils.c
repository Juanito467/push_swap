/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:24:52 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 10:24:52 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
// int	stack_check(t_stack *a)
// {
// 	while (a && a->next)
// 	{
// 		if (a > a->next)
// 			return (1);
// 		a = a->next;
// 	}
// 	return (0);
// }
t_stack	*ft_stacknew(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
    list->previous = NULL; // falta esto
	return (list);
}
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
    new->previous = temp;
}
void	ft_stack_clear(t_stack **stack)
{
	t_stack *temp;
	t_stack *next;

	temp = *stack;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}
int	ft_stacksize(t_stack *stack)
{
	t_stack *temp;
	int	i;

	i = 0;
	temp = stack;
	if (!stack)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
