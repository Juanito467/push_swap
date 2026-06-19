/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:04:18 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/16 09:52:55 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

t_stack	*ft_min(t_stack *a)
{
	printf("FT_MIN!\n");
	t_stack	*min;
	t_stack	*walk;

	min = a;
	walk = a;
	while (walk)
	{
		if (min->content > walk->content)
			min = walk;
		walk = walk->next;
	}
	return (min);
}

t_stack	*ft_max(t_stack *a)
{
	t_stack	*max;
	t_stack	*walk;
	
	max = a;
	walk = a;
	while (walk)
	{
		if (max->content < walk->content)
			max = walk;
		walk = walk->next;
	}
	return (max);
}

