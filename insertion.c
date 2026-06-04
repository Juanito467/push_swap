/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:30:45 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/04 14:39:00 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotations_cost(t_stack **b, int value)
{
	int		rotations;
	t_stack	*temp;
	t_stack	*max;
	t_stack	*min;

	if (!*b)
		return (0);
	max = ft_max(b);
	if (value > max->content)
		return (0);
	min = ft_min(b);
	if (value < min->content)
		return (1);
	temp = *b;
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
void	insertion(t_stack **a, t_stack **b)
{
}