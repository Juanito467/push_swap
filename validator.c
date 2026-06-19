/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:29:34 by davgonca          #+#    #+#             */
/*   Updated: 2026/06/19 12:19:11 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_dupes(char **argv)
{
	int	i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int ft_is_not_int(char *argv)
{
    int i;

    i = 0;
    while (argv[i])
	{                   
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

