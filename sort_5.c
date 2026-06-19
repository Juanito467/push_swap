/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:30:21 by davgonca          #+#    #+#             */
/*   Updated: 2026/06/16 12:04:49 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack **a)
{
    t_stack *min;
    t_stack *max;

    min = ft_min(*a);
    max = ft_max(*a);
    if (max == *a && min == (*a)->next)
		ra(a);
	else if (max == *a && min == (*a)->next->next)
	{
		sa(a);
		rra(a);
	}
	else if (max == (*a)->next && min == *a)
	{
		sa(a);
		ra(a);		
	}
	else if (max == (*a)->next->next)
		sa(a);
	else if (max == (*a)->next && min == (*a)->next->next)
		rra(a);
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	int i;

	i = 0;
	while (ft_stacksize(*a) > 3)
	{
		rotmin(a, size - i);
		pb(a, b);
		i++;
	}
	sort_3(a);
	while(*b)
		pa(a, b);
}

void	rotmin(t_stack **a, int size)
{
	int	i;
	t_stack	*walk;
	t_stack	*target;
	
	target = ft_min(*a);
	i = 0;
	walk = *a;
	while (walk != target)
	{
		walk = walk->next;
		i++;
	}
	if ((size / 2) < i)
	{
		while (*a != target)
			ra(a);
	}
	else if ((size / 2) >= i)
	{
		while (*a != target)
			rra(a);
	}
}

void	rotmax(t_stack **a, int size)
{
	int	i;
	t_stack	*walk;
	t_stack	*target;
	
	target = ft_max(*a);
	i = 0;
	walk = *a;
	while (walk != target)
	{
		walk = walk->next;
		i++;
	}
	if ((size / 2) < i)
	{
		while (*a != target)
			ra(a);
	}
	if ((size / 2) >= i)
	{
		while (*a != target)
			rra(a);
	}
}