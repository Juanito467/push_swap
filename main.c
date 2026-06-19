/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:10:01 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 12:37:07 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_creator(int argc, char **argv)
{
	int		i;
	int		*array;

	if (argc == 1)
		return (NULL);
	i = 0;
	array = malloc(sizeof(int) * (argc));
	if (!array)
		return (NULL);
	while (i < argc)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

int	main(int argc, char **argv)
{
	t_info info;
	int		*array;
	t_stack	*a;
	t_stack	*b;

	if (parsing(&info, argv + 1))
		return (1);
	array = array_creator(argc - 1, argv + 1);
	if (!array)
		return (0);
	info.disorder = disorder(array, argc - 1);
	b = NULL;
	a = stack_creator(array, argc - 1);
	free(array);
	if (!a)
		return (0);
	ft_print_stack(&a);
	printf("==================================\n");
	orchestrator(&a, &b, &info);
	ft_print_stack(&a);
	ft_stack_clear(&a);
	return (0);
}
