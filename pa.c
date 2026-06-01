/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:18:24 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/01 17:08:02 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	(*a)->previous = temp;
	*b = (*b)->next;
}

void	pb(t_stack **a, t_stack **b)
{
	pa(a, b);
}
