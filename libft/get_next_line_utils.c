/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:50:16 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/04 13:16:52 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_checklen(char *str, char str_line)
{
	size_t	i;

	i = 0;
	if (str_line == 's')
	{
		while (str[i])
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
			i++;
		return (i);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_check_new_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}	
	return (0);
}

char	*ft_clean_line(char *line)
{
	size_t	end_line;

	end_line = ft_checklen(line, 'l');
	while (line[end_line])
	{
		line[end_line] = '\0';
		end_line++;
	}
	return (line);
}
