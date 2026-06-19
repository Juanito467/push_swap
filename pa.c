/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:18:24 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/17 16:10:44 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	if (!*b)
		return;
	temp = *b;	
	*b = (*b)->next;
	temp->next = *a;
	if (*a)
		(*a)->previous = temp;
	temp->previous = NULL;
	*a = temp;
}


void	pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*a)
		return ;
	temp = *a;	
	*a = (*a)->next;
	temp->next = *b;
	if (*b)
		(*b)->previous = temp;
	temp->previous = NULL;
	*b = temp;
}
