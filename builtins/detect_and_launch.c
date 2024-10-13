/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_and_launch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:18:05 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 11:49:39 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	detect_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd) + 1) == 0)
		return (CD);
	else if (ft_strncmp(cmd, "echo", ft_strlen(cmd) + 1) == 0)
		return (ECHO);
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd) + 1) == 0)
		return (ENV);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd) + 1) == 0)
		return (EXIT);
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd) + 1) == 0)
		return (EXPORT);
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd) + 1) == 0)
		return (PWD);
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd) + 1) == 0)
		return (UNSET);
	return (-1);
}

int	launch_if_builtin(char **array, t_state *s)
{
	int	bltn;

	bltn = detect_builtin(array[0]);
	if (bltn == -1)
		return (0);
	else if (bltn == CD)
		s->exit_code = ft_cd(array, s);
	else if (bltn == ECHO)
		s->exit_code = ft_echo(array);
	else if (bltn == ENV)
		s->exit_code = ft_env(s->env);
	else if (bltn == EXIT)
		s->exit_code = ft_exit(array, s);
	else if (bltn == EXPORT)
		s->exit_code = ft_export(&(array[1]), s);
	else if (bltn == PWD)
		s->exit_code = ft_pwd(s);
	else if (bltn == UNSET)
		s->exit_code = ft_unset(&(array[1]), s);
	return (1);
}
