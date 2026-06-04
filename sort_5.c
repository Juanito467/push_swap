/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:30:21 by davgonca          #+#    #+#             */
/*   Updated: 2026/06/04 12:30:32 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack **a)
{
    t_stack *min;
    t_stack *max;

    min = ft_min(a);
    max = ft_max(a);
    if (max == *a && min == (*a)->next)
		ra(a);
	if (max == *a && min == (*a)->next->next)
	{
		sa(a);
		rra(a);
	}
	if (max == (*a)->next && min == *a)
	{
		sa(a);
		ra(a);		
	}
	if (max == (*a)->next->next)
		sa(a);
	if (max == (*a)->next && min == (*a)->next->next)
		ra(a);
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	rotmin(a, size);
	pb(a, b);
	rotmin(a, size - 1);
	pb(a, b);
	sort_3(a);
	rotmax(b, 2);
	pa(b, a);
	pa(b, a);
}

void	rotmin(t_stack **a, int size)
{
	int	i;
	t_stack	*walk;
	t_stack	*target;
	
	target = ft_min(a);
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

void	rotmax(t_stack **a, int size)
{
	int	i;
	t_stack	*walk;
	t_stack	*target;
	
	target = ft_max(a);
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