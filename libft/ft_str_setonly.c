/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_setonly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:00:41 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:45:01 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_setonly(char *str, char *set)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	check = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] != str[i])
				check = 1;
			if (set[j] == str[i])
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check == 1)
			return (1);
		i++;
	}
	return (0);
}
