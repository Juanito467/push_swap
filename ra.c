/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:07:00 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/15 18:32:48 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a) //node 3, node 1, node 2
{
	t_stack	*temp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a; // temp = node 3
	*a = (*a)->next; //a = node 1
	(*a)->previous = NULL; // node 1 is the first one now
	last = ft_stacklast(*a); // the last is 2 at this point, 
	last->next = temp; // node 2.next will be node 3
	temp->previous = last; // node 3 previous will be the last. 
	temp->next = NULL; // then temp.next will be null. Everything is correct. 
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
