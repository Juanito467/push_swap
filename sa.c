/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:54:00 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/01 17:04:38 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (!a || a->next == NULL)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
}

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
}
