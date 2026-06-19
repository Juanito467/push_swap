/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:39:40 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/17 15:01:58 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_creator(int *array, int size)
{
	int i;
	t_stack *new_node;
	t_stack *a;

	i = 0;
    a = NULL;
	while (i < size)
	{
		new_node = ft_stacknew(array[i]);
		if (i == 0)
			a = new_node;
		else
			ft_stackadd_back(&a, new_node);
		i++;
	}
	return (a);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			return (0);
		i++;
	}
	return (1);
}
