/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpolania <jpolania@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:24:13 by jpolania          #+#    #+#             */
/*   Updated: 2026/06/19 12:40:52 by jpolania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parsing(t_info *info, char **argv)
{
    int count;
    int i;
    
    i = 0;
    count = flags_validator(info, argv);
    if (info->flags == ERROR)
        return (1);
    if (validate_dupes(argv))
        return (1);
    while (argv[i])
    {
        if ((ft_is_not_int(argv[i])))
		    return (1);
    }
    return (count);
}