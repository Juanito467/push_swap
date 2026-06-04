/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonca <davgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:07:00 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/02 22:53:02 by davgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last = ft_stacklast(*a);
	last->next = temp;
	temp->previous = last;
	temp->next = NULL;
}

void	rb(t_stack **b)
{
	ra(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
