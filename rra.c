/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:07:47 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/01 17:23:35 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;

	last = ft_stacklast(*a);
	last->previous->next = NULL;
	last->next = *a;
	*a = last;
	(*a)->previous = NULL;
}
void	rrb(t_stack **b)
{
	rra(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}