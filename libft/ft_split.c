/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:48:33 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/16 13:57:28 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wrdcount(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			i++;
		count++;
	}
	if (i - 1 < 0)
		return (0);
	if (str[i - 1] == c)
		count--;
	return (count);
}

static size_t	ft_wrd_end(const char *str, char c, size_t start)
{
	size_t	end;

	end = start;
	while (str[end] != c && str[end])
		end++;
	return (end);
}

static char	*make_word(const char *s, char c, size_t start)
{
	size_t	end;
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	end = ft_wrd_end(s, c, start);
	len = (end - start);
	str = (char *)g_malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start + i] && s[start + i] != c)
	{
			str[i] = s[start + i];
			i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	w_count;
	char	**tab;

	i = 0;
	w_count = ft_wrdcount(s, c);
	tab = (char **)ft_calloc((w_count + 1), (sizeof(char *)));
	if (!tab)
		return (NULL);
	if (*s == '\0')
		return (tab[0] = NULL, tab);
	w_count = 0;
	while (s[i])
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			tab[w_count] = make_word(s, c, i);
			if (!tab[w_count])
				return (ft_free_all(tab), NULL);
			w_count++;
		}
		i++;
	}
	tab[w_count] = NULL;
	return (tab);
}
