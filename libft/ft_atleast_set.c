/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atleast_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:07:56 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:35:48 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atleast_char(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atleast_set(char *str, char *set)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (str[i] && set[j])
	{	
		if (ft_atleast_char(str, set[j]) == 1)
		{
			check = 1;
			j++;
		}
		i++;
		if (check == 1)
		{
			i = 0;
			check = 0;
		}
	}
	if (set[j] == '\0')
		return (1);
	return (0);
}

void	ft_init_zero(t_index *i)
{
	i->i = 0;
	i->j = 0;
	i->k = 0;
	i->len = 0;
	i->check = 0;
}

int	ft_tabatleast_char(char **tab, char c)
{
	t_index	i;

	ft_init_zero(&i);
	while (tab[i.i])
	{
		if (ft_atleast_char(tab[i.i], c) == 1)
			return (1);
		i.i++;
	}
	return (0);
}

int	ft_tabatleast_set(char **tab, char *set)
{
	t_index	i;

	ft_init_zero(&i);
	while (tab[i.i] && set[i.j])
	{	
		if (ft_tabatleast_char(tab, set[i.j]) == 1)
		{
			i.check = 1;
			i.j++;
		}
		i.i++;
		if (i.check == 1)
		{
			i.i = 0;
			i.check = 0;
		}
	}
	if (set[i.j] == '\0')
		return (1);
	return (0);
}
