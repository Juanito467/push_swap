/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 12:30:45 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 10:11:46 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion(t_stack **a, t_stack **b, int size)
{
	int cheapest;
	int rotations_b;
	int i;

	i = 0;
	while (size != i)
	{
		if (!*b)
			pb(b,a);
		cheapest = find_cheapest(a, b, size - i);
		rotate_a_to_position(a, cheapest, size - i);
		rotations_b = ft_rotations_cost(*b, (*a)->content);
		rotate_b_to_position(b, rotations_b, size - i);
		pb(b, a);
		i++;
	}
	while (*b)
		pa(a, b);
}
