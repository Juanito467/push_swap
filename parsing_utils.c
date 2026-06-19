/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:25:44 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 12:37:21 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"













int    flags_validator(t_info *info, char **argv)
{
    int i;
    
    i = 0;
    while (argv[i][0] == '-' && argv[i][1] == '-')
    {
        if(!(ft_strcmp(argv[i], "--simple")))
            info->flags = SIMPLE;
        else if (!(ft_strcmp(argv[i], "--medium")))
            info->flags = MEDIUM;
        else if (!(ft_strcmp(argv[i], "--complex")))
            info->flags = COMPLEX;
        else if (!(ft_strcmp(argv[i], "--adaptative")))
            info->flags = ADAPTATIVE;
        else if (!(ft_strcmp(argv[i], "--bench")))
            info->bench = 1;
        else
            info->flags = ERROR;
        i++;
    }
    if (argv[i] == NULL)
        return (info->flags = ERROR);
    return (i);
}