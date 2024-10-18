/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:28:28 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/16 15:22:38 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_getenv_path(char **env, t_info_exec *info)
{
	char	**temp;
	char	*path;

	if (!*env)
		return (2);
	temp = env;
	while (*temp)
	{
		if (ft_strncmp("PATH=", *temp, 5) == 0)
		{
			path = ft_strtrim(*temp, "PATH=");
			if (!path)
				return (ft_free_all(info->arg), 1);
			info->t_path = ft_split(path, ':');
			if (!info->t_path)
				return (g_free(path), ft_free_all(info->arg), 1);
			g_free(path);
			return (0);
		}
		temp++;
	}
	return (2);
}

int	ft_check_ifpath(t_info_exec *info)
{
	if (ft_strchr(info->cmd, '/') == NULL)
		return (0);
	info->path = ft_strdup(info->cmd);
	if (!info->path)
		return (ft_free_all(info->arg), 2);
	info->cmd = ft_strdup(info->cmd);
	if (!info->cmd)
		return (g_free(info->path), ft_free_all(info->arg), 2);
	info->t_path = ft_split(info->cmd, ' ');
	if (!info->t_path)
		return (g_free(info->cmd), g_free(info->path), ft_free_all(info->arg), 2);
	return (1);
}

int	ft_find_cmd(t_info_exec *info)
{
	char	*path;
	char	**path_tab;

	info->cmd = ft_strjoin("/", info->cmd);
	if (!info->cmd)
		return (ft_free_all(info->arg), 1);
	path_tab = info->t_path;
	while (*path_tab)
	{
		path = ft_strjoin(*path_tab, info->cmd);
		if (!path)
			return (g_free(info->cmd), ft_free_all(info->arg), 1);
		if (access(path, F_OK) == 0)
		{
			info->path = ft_strdup(path);
			if (!info->path)
				return (g_free(path), g_free(info->cmd), ft_free_all(info->arg), 1);
			g_free(path);
			return (0);
		}
		g_free(path);
		path_tab++;
	}
	return (2);
}

int	ft_path_bis(int find_cmd, t_info_exec *info)
{
	if (find_cmd == 2)
	{
		info->path = ft_strdup(info->cmd + 1);
		if (!info->path)
		{
			g_free(info->path);
			g_free(info->cmd);
			ft_free_all(info->arg);
			return (1);
		}
	}
	return (0);
}

int	ft_path(char **env, t_info_exec *info)
{
	int	ifpath;
	int	getenv_path;
	int	find_cmd;

	ifpath = ft_check_ifpath(info);
	if (ifpath == 1)
		return (0);
	if (ifpath == 2)
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	getenv_path = ft_getenv_path(env, info);
	if (getenv_path == 1)
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	if (getenv_path == 2)
		return (ft_execve_stuff(info), 0);
	find_cmd = ft_find_cmd(info);
	if (find_cmd == 0)
		return (0);
	if (find_cmd == 1)
		return (ft_putstr_fd("Malloc failed\n", 2), 1);
	return (ft_path_bis(find_cmd, info));
}
