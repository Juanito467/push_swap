/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonca <davgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:07:47 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/12 17:40:00 by davgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack **a)
{
    t_stack *last;
    t_stack *head;

    if (!*a || !(*a)->next)
        return ;
    head = *a;
    last = ft_stacklast(*a);
    last->previous->next = NULL;   
    last->previous = NULL;         
    last->next = head;             
    head->previous = last;         
    *a = last;                     
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