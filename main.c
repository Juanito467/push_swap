/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:10:01 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/04 11:28:34 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**stack_creator(int *array, int size)
{
	int		i;
	t_stack	*new_node;
	t_stack	*last;
	t_stack	**a;

	i = 0;
    a = malloc(sizeof(t_stack *));
	while (i < size)
	{
		new_node = ft_lstnew(array[i]);
		if (i == 0)
			*a = new_node;
		else
			ft_lstadd_back(a, new_node);
		i++;
	}
	return (a);
}
int ft_is_int(char **argv, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {   
            if (argv[i][0] == '-')
                
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                return (1);
            j++;
        }
        i++;
    }
	return (0);
}


int	main(int argc, char **argv)
{
	int	i;
	int	*array;

    if (argc == 1 || ft_is_int(argv, argc - 1))
        return (0);
    i = 0;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (0);
	while (i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
		printf("%d\n", array[i]);
		i++;
	}
    if (validate_dupes(array, i))
    {
        free(array);
        return (0);
    }
    stack_creator(array, i);
    free(array);
	return (0);
}
