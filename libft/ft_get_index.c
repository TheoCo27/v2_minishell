/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:08 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:46:10 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_init_t_point(t_point *index)
{
	index->x = 0;
	index->y = 0;
}

t_point	ft_tab_findchar(char **tab, char c)
{
	t_point	index;

	ft_init_t_point(&index);
	while (tab[index.x])
	{
		index.y = ft_findchar(tab[index.x], c);
		if (index.y != -1)
			return (index);
		index.x++;
	}
	index.x = -1;
	return (index);
}
