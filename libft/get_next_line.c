/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:50:20 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:52:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_g_free_join(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	char	*temp_line;

	line_len = ft_checklen(line, 's');
	buffer_len = ft_checklen(buffer, 's');
	temp_line = (char *)g_malloc((line_len + buffer_len + 1) * sizeof(char));
	if (!temp_line)
		return (g_free(line), NULL);
	ft_strcpy(temp_line, line);
	g_free(line);
	ft_strcpy(&temp_line[line_len], buffer);
	return (temp_line);
}

static char	*ft_read_file(int fd, char *line, char *buffer)
{
	long	read_output;

	read_output = 0;
	while (ft_check_new_line(line) == 0)
	{
		buffer[0] = '\0';
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)
			return (g_free(line), NULL);
		buffer[read_output] = '\0';
		if (read_output == 0)
			break ;
		line = ft_str_g_free_join(line, buffer);
		if (!line)
			return (g_free(line), NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	rest_line[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = (char *)g_malloc((ft_checklen(rest_line, 's') + 1) * sizeof(char));
	line[0] = '\0';
	ft_strcpy(line, rest_line);
	line = ft_read_file(fd, line, rest_line);
	if (!line)
		return (g_free(line), NULL);
	if (ft_check_new_line(line) == 1)
	{
		ft_strcpy(rest_line, &line[ft_checklen(line, 'l')]);
		ft_clean_line(line);
	}
	if (ft_check_new_line(line) == 0)
	{
		rest_line[0] = '\0';
		if (line [0] == '\0')
			return (g_free(line), NULL);
	}
	return (line);
}

/*int main()
{
	char *line;
	char c;
	int fd;

	
	fd = open("test.txt", O_RDONLY);
	c = '\0';
	line = &c;
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		g_free(line);
	}
	return (0);
}*/
