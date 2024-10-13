/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:57:04 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:51:04 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(const char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_getlen(char const *s1, char const *set, int start)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	while ((s1[i]) && (ft_checkset(s1[i], set) == 1))
		i++;
	if (start == 1)
		return (i);
	if (len_s1 == i)
		return (0);
	j = len_s1 - 1;
	while (ft_checkset(s1[j], set) == 1)
	{
		j--;
		i++;
	}
	return (len_s1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i;
	size_t	len_trim;
	char	*s_trim;

	if (!s1 || !set)
		return (ft_strdup(""));
	len_trim = ft_getlen(s1, set, 0);
	i = 0;
	i_start = ft_getlen(s1, set, 1);
	s_trim = (char *)g_malloc((sizeof(char)) * (len_trim + 1));
	if (!s_trim)
		return (NULL);
	while (i < len_trim)
	{
		s_trim[i] = s1[i_start + i];
		i++;
	}
	s_trim[i] = '\0';
	return (s_trim);
}
