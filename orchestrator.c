/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestrator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:02:35 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 13:53:27 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orchestrator(t_stack **a, t_stack **b, t_info *info)
{
    if (info->flags == ADAPTATIVE)
        return ;
    if (info->disorder == 0.0)
        return ;
	else if (info->size <= 3)
		sort_3(a);
    else if (info->size <= 5)
        sort_5(a, b, info->size);
	else if (info->flags == SIMPLE)
    {
        printf("We are going to use Insertion!\n");
        insertion(a, b, info->size);
    }
}

void    ft_print_stack(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while(temp)
    {
        printf("Each value : %d\n", temp->content);
        temp = temp->next;    
    }    
}


