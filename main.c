/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:10:01 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 13:30:53 by jpolania         ###   ########.fr       */
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
	
	printf("Running Main\n");
	if (parsing(&info, argv + 1))
		return (0);
	printf("1\n");
	info.size = (argc - 1) - info.skip_position;
	printf("1\n");
	array = array_creator(info.size, argv + 1);
	if (!array)
		return (0);
	info.disorder = disorder(array, info.size);
	b = NULL;
	a = stack_creator(array, info.size);
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
