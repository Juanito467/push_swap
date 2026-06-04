/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:44:26 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/03 11:31:52 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float disorder (int *stack, int size)
{
    float mistakes;
    float total_pairs;
    int i;
    int j;
    
    i = 0;
    mistakes = 0;
    total_pairs = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total_pairs += 1;
            if (stack[i] > stack[j])
                mistakes += 1;
        }
        i++;
    }
    return (mistakes / total_pairs);
}