/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:54:00 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/15 15:57:13 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;
    t_stack *thirst;

    if (!a || !*a)
        return ;
    first = *a;
    second = (*a)->next;
    thirst =(*a)->next->next;
    first->previous = second;
    first->next = thirst;
    thirst->previous = first;
    second->next = first;
    second->previous = NULL;
    *a = second;
}

void	sb(t_stack **b)
{
	sa(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sa(b);
}
