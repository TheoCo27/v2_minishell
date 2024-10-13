/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:32:01 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:52:48 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tabstr_len(char **tabstr)
{
	size_t	i;

	i = 0;
	if (tabstr == NULL)
		return (0);
	while (tabstr[i])
		i++;
	return (i);
}

char	**ft_tabstr_copy(char **tabstr)
{
	size_t	tab_len;
	char	**tab_copy;
	size_t	i;

	i = 0;
	tab_len = ft_tabstr_len(tabstr);
	if (tab_len == 0)
		return (NULL);
	tab_copy = (char **)g_malloc((tab_len + 1) * sizeof(char *));
	if (!tab_copy)
		return (NULL);
	while (i < tab_len)
	{
		tab_copy[i] = ft_strdup(tabstr[i]);
		if (!tab_copy[i])
			return (ft_free_all(tab_copy), NULL);
		i++;
	}
	tab_copy[tab_len] = NULL;
	return (tab_copy);
}

void	ft_print_tabstr(char **tabstr)
{
	char	**temp;

	temp = tabstr;
	if (temp == NULL || *temp == NULL)
		return ;
	while (*temp)
	{
		ft_putendl_fd(*temp, 1);
		temp++;
	}
}

char	**ft_make_tabstr(void)
{
	char	**tab_str;

	tab_str = (char **)g_malloc(sizeof(char *));
	if (!tab_str)
		return (NULL);
	*tab_str = NULL;
	return (tab_str);
}

char **ft_temptab_totab(char **tab_dest, char **tab_src)
{
	size_t	i;

	i = 0;
	while(tab_src[i])
	{
		tab_dest[i] = &(*(tab_src[i]));
		i++;
	}
	tab_dest[i] = NULL;
	return (tab_dest);
}

char	**ft_tabstr_addback(char *str, char **tab_str)
{
	size_t	tabstr_len;
	char	**temp_tab;
	char	*str_dup;

	str_dup = ft_strdup(str);
	temp_tab = tab_str;
	if (!str_dup)
		return(ft_free_all(temp_tab), NULL);
	tabstr_len = ft_tabstr_len(tab_str);
	tab_str = (char **)g_malloc((tabstr_len + 2) * sizeof(char *));
	if (!tab_str)
		return(g_free(str_dup), ft_free_all(temp_tab), NULL);
	ft_temptab_totab(tab_str, temp_tab);
	tab_str[tabstr_len] = &(*(str_dup));
	tab_str[tabstr_len + 1] = NULL;
	g_free(temp_tab);
	return (tab_str);
}
