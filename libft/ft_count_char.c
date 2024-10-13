/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:45:05 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:36:46 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_tabcount_char(char **tab, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		count += ft_count_char(tab[i], c);
		i++;
	}
	return (count);
}
