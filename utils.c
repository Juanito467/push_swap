/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:04:18 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/04 11:50:48 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	stack_check(t_stack *a)
{
	while (a && a->next)
	{
		if (a > a->next)
			return (1);
		a = a->next;
	}
	return (0);
}

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

t_stack	*ft_lstnew(void *content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_stack	*ft_min(t_stack **a)
{
	t_stack	*min;
	t_stack	*walk;

	min = *a;
	walk = *a;
	while (walk)
	{
		if (min->content > walk->content)
			min = walk;
		walk = walk->next;
	}
	return (min);
}

t_stack	*ft_max(t_stack **a)
{
	t_stack	*max;
	t_stack	*walk;
	
	max = *a;
	walk = *a;
	while (walk)
	{
		if (max->content < walk->content)
			max = walk;
		walk = walk->next;
	}
	return (max);
}

