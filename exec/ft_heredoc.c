/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:29 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 20:42:42 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	ft_open(char *file_name, char mode, t_info_exec *info)
// {
// 	int	fd;

// 	if (mode == 'h')
// 		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
// 	if (fd < 0)
// 	{
// 		perror(file_name);
// 		ft_close_pipe(info->pipe_fd);
// 		//ft_close_remaining_pipes(cmd, lst);
// 		//ft_pipelst_clear(lst);
// 		exit(errno);
// 	}
// 	return (fd);
// }

static char	*ft_anti_fuck_heredoc(char *file_name)
{
	while(access(file_name, F_OK) == 0)
	{
		file_name = ft_str_free_s1_join(file_name, "1");
		if (!file_name)
			return (g_free(file_name), NULL);
	}
	return (file_name);
}

int	ft_name_heredocs(t_info_exec **lst)
{
	t_info_exec *cmd;
	t_file_lst	*file;
	char		*name;

	cmd = *lst;
	name = ft_strdup(".heredoc");
	if (!name)
		return (-1);
	while(cmd)
	{
		file = cmd->file_lst;
		while(file)
		{
			if (file->type == 'h')
			{
				name = ft_str_free_s1_join(name, "1");
				name = ft_anti_fuck_heredoc(name);
				if (!name)
					return (-1);
				file->name = ft_strdup(name);
				if (!file->name)
					return (-1);
			}
			file = file->next;
		}
		cmd = cmd->next;
	}
	return (0);
}


int ft_fill_all_heredocs(t_info_exec **lst)
{
	t_info_exec *cmd;
	t_file_lst	*file;

	cmd = *lst;
	while(cmd)
	{
		file = cmd->file_lst;
		while(file)
		{
			if (file->type == 'h')
				ft_fill_heredoc(file->delimiter, file->name, cmd, lst);
			file = file->next;
		}
		cmd = cmd->next;
	}
	return (0);
}

// int ft_fill_heredoc(char *limiter, char *filename, t_info_exec *cmd, t_info_exec **lst)
// {
// 	char	*line;
// 	size_t	limiter_len;
// 	int		fd;
	
// 	fd = ft_open(filename, 'h', cmd, lst);
// 	line = NULL;
// 	limiter_len = ft_strlen(limiter);
// 	// if (ft_checkif_heredoc() == 1)
// 	// 	ft_fill_heredoc(limiter, filename, cmd, lst);
// 	while(1)
// 	{
// 		ft_putstr_fd("heredoc> ", 1);
// 		line = get_next_line(0);
// 		if (!line)
// 			break;
// 		if (ft_strncmp(line, limiter, limiter_len) == 0 && line[limiter_len] == '\n')
// 		{
// 			g_free(line);
// 			break;
// 		}
// 		ft_putstr_fd(line, fd);
// 		g_free(line);
// 	}
// 	close (fd);
// 	return (0);
// }
int ft_fill_heredoc(char *limiter, char *filename, t_info_exec *cmd, t_info_exec **lst)
{
	char	*line;
	size_t	limiter_len;
	int		fd;
	
	fd = ft_open(filename, 'h', cmd, lst);
	line = NULL;
	limiter_len = ft_strlen(limiter);
	while(1)
	{
		line = readline("heredoc> ");
		if (!line)
			break;
		if (ft_strncmp(line, limiter, limiter_len) == 0)
		{
			g_free(line);
			break;
		}
		ft_putendl_fd(line, fd);
		g_free(line);
	}
	close (fd);
	return (0);
}

int ft_destroy_heredocs(t_info_exec **lst)
{
	t_info_exec *cmd;
	t_file_lst	*file;

	cmd = *lst;
	while(cmd)
	{
		file = cmd->file_lst;
		while(file)
		{
			if (file->type == 'h')
			{
				unlink(file->name);
			}
			file = file->next;
		}
		cmd = cmd->next;
	}
	return (0);
}
t_heredoc *ft_make_heredoc(t_info_exec *cmd, t_info_exec **lst)
{
	t_heredoc *h;

	h = g_malloc(sizeof(t_heredoc) * 1);
	if (!h)
		return (NULL);
	h->heredoc_name = ft_strdup("heredoc");
	if (!h->heredoc_name)
		return (NULL);
	h->heredoc_name = ft_anti_fuck_heredoc(h->heredoc_name);
	if (!h->heredoc_name)
		return (NULL);
	h->fd_heredoc = ft_open(h->heredoc_name, 'h', cmd, lst);
	return (h);
}

// int main(int argc, char **argv)
// {
// 	t_heredoc *h;
// 	char *line;
// 	int i = 1;

// 	char c = 'a';
// 	line = &c;
// 	if (argc < 2)
// 	{
// 		ft_putstr_fd("error need ./hey_doc <your_limiter>", 2);
// 		exit(1);
// 	}
// 	h = ft_make_heredoc(argv[1]);
// 	while(argv[i])
// 	{
// 		ft_fill_heredoc(argv[i], h->fd_heredoc);
// 		i++;
// 	}
// 	close(h->fd_heredoc);
// 	h->fd_heredoc = ft_open(h->heredoc_name, 'r');
// 	while(line)
// 	{
// 		line = get_next_line(h->fd_heredoc);
// 		if (!line)
// 			break;
// 		ft_putstr_fd(line, 1);
// 		g_free(line);
// 	}
// 	ft_destroy_heredoc(h);
// 	return (0);

// }

// int	main(void)
// {
// 	char buffer[1024];
// 	int read_output;

// 	while((read_output = read(0, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[read_output] = '\0';
// 		printf("ligne lue : %s\n", buffer);
// 	}
// 	printf("fin du heredoc");
// 	return (0);
// }
