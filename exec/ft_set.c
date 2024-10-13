/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:04:24 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 20:45:52 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execve_stuff(t_info_exec *info)
{
	info->path = ft_strdup(info->cmd);
	if (!info->path)
		return (ft_free_all(info->arg), 1);
	info->cmd = ft_strdup(info->cmd);
	if (!info->cmd)
		return (g_free(info->path), ft_free_all(info->arg), 1);
	info->t_path = ft_split(info->cmd, ' ');
	if (!info->t_path)
		return (g_free(info->cmd), g_free(info->path), ft_free_all(info->arg), 1);
	return (0);
}
