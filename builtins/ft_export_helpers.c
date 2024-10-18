/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:52:59 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/16 18:23:55 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	find_nth_elem(char **array, int pos)
{
	int	i;
	int	j;
	int	inferior;

	i = 0;
	while (array[i])
	{
		j = 0;
		inferior = 0;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) > 0)
				inferior++;
			j++;
		}
		if (inferior == pos)
			return (i);
		i++;
	}
	return (0);
}

char	**char_star_array_sort(char **array, t_state *s)
{
	char	**new_array;
	int		i;
	int		len;

	if (!array)
		return (NULL);
	len = sal(array);
	new_array = ft_malloc(sizeof(char *) * (len + 1), &(s->gc), s);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[find_nth_elem(array, i)];
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

char	**make_char_s_arr_from_str(char *str, t_state *s)
{
	char	**array;

	array = ft_malloc(sizeof(char *) * 2, &(s->gc), s);
	if (!array)
		return (NULL);
	array[0] = str;
	array[1] = NULL;
	return (array);
}

void	put_export_unvalid_regex(char *str, int *code, int *i)
{
	ft_putstr_fd("bash: export: '", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	*code = 1;
	*i += 1;
}
