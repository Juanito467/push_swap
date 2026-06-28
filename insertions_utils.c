/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:27:30 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/28 06:21:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_in_b(t_stack *b, int value)
{
	int 	size_b;
	int		rotations;
	t_stack	*temp;
	t_stack	*max;
	t_stack	*cost_min;

	if (!b)
		return (0);
	temp = b;
	size_b = ft_stacksize(b);
	rotations = 0;
	max = ft_max(b);
	if (value > max->content)
	{
		while (temp && temp->content != max->content)
		{
			rotations++;
			temp = temp->next;
		}
		if (rotations < size_b / 2)
			return (rotations);
		else
			return (rotations - size_b);
	}
	cost_min = ft_min(b);
	if (value < cost_min->content)
	{
		while (temp && temp->content != cost_min->content)
		{
			rotations++;
			temp = temp->next;
		}
		if (rotations < size_b / 2)
			return (rotations);
		else
			return (rotations - size_b);
	}
	
	while (temp)
	{
		if (temp->next && (temp)->content > value
			&& (temp)->next->content < value)
		{
			if (rotations < size_b / 2)
				return (rotations);
			else
				return (rotations - size_b);
		}
		rotations++;
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
				return (-(size - i));
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
	int 	total_cost;
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
		cost_b = ft_cost_in_b(*b, temp->content);
		total_cost = ft_total_cost(cost_a, cost_b);
		printf("Cost a: %d\n", cost_a);
		printf("Cost b: %d\n", cost_b);
		printf("Total cost: %d\n", total_cost);
		if (total_cost < cost_min)
		{
			cost_min = total_cost;
			cheapest = index;
		}
		index++;
		temp = temp->next;
	}
	printf("The value in the current cheapest is: %d\n", cheapest);
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

int     ft_total_cost(int a, int b)
{
    int result;
    
    result = 0;
    if (a >= 0 && b >= 0)
    {
        if (a > b)
            result = a;
        else
            result = b;
        return (result);
    }
    if(a <= 0 && b <= 0) //exemplo a = -5 b = -2
    {
        if (a < b)
            result = -a;
        else
            result = -b;
        return (result);
    }
    if (a > 0 && b < 0)
        result = a + (-b);
    if (a < 0 && b > 0)
        result = (-a) + b;
    return (result);
}
