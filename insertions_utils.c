/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:27:30 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 12:36:31 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotations_cost(t_stack *b, int value)
{
	int		rotations;
	t_stack	*temp;
	t_stack	*max;
	t_stack	*cost_min;

	if (!b)
		return (0);
	max = ft_max(b);
	if (value > max->content)
		return (0);
	cost_min = ft_min(b);
	if (value < cost_min->content)
		return (1);
	temp = b;
	rotations = 0;
	while (temp)
	{
		if (temp->next && (temp)->content > value
			&& (temp)->next->content < value)
			return (rotations);
		rotations += 1;
		temp = temp->next;
	}
	return (0); 
}
int	ft_cost_in_a(t_stack *a, int value, int size)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = 0;
	while (temp)
	{
		if (temp->content == value)
		{
			if (i < size / 2)
				return (i);
			else
				return (size - i);
		}
		i += 1;
		temp = temp->next;
	}
	return (0);
}

int	find_cheapest(t_stack **a, t_stack **b, int size)
{
	t_stack	*temp;
	int		cost_min;
	int		cost_a;
	int		cost_b;
	int		cheapest;
	int		index;

	temp = *a;
	cost_min = __INT_MAX__;
	index = 0;
	while (temp)
	{
		cost_a = ft_cost_in_a(*a, temp->content, size);
		cost_b = ft_rotations_cost(*b, temp->content);
		if ((cost_a + cost_b) < cost_min)
		{
			cost_min = cost_a + cost_b;
			cheapest = index;
		}
		index++;
		temp = temp->next;
	}
	return (cheapest);
}
void	rotate_a_to_position(t_stack **a, int position, int size)
{
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
		while (position < size)
		{
			rra(a);
			position++;
		}
}
void	rotate_b_to_position(t_stack **b, int rotations, int size)
{
	if (rotations <= size / 2)
		while (rotations > 0)
		{
			rb(b);
			rotations--;
		}
	else
		while (rotations < size)
		{
			rrb(b);
			rotations++;
		}
}
