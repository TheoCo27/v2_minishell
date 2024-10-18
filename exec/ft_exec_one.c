/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 02:11:10 by theog             #+#    #+#             */
/*   Updated: 2024/10/16 15:16:54 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_only_child(t_info_exec *cmd, char **env, t_info_exec **lst)
{
    int status;

    status = 0;
    cmd->pid = fork();
    if (cmd->pid == 0)
    {
        // ft_cmd_arg(cmd->cmd, cmd, lst);

		ft_redir_all(cmd, lst); //leaks free till here
		if (launch_if_builtin(cmd->arg, cmd->state) == 1)
			return( garbage_destroy(), cmd->state->exit_code);
        if (ft_path(env, cmd) == 1)
			return(garbage_destroy(), 1);
	    ft_execve(cmd, lst);
    }
    status = ft_wait_pids(*lst, status);
    ft_destroy_heredocs(lst);
    garbage_destroy();
	return (status);
}