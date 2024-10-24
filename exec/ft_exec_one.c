/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 02:11:10 by theog             #+#    #+#             */
/*   Updated: 2024/10/24 16:49:04 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../signal/ft_signal.h"

int	ft_only_child(t_info_exec *cmd, char **env, t_info_exec **lst)
{
    int status;

    status = 0;
    cmd->pid = fork();
    if (cmd->pid == 0)
    {
		set_exec_sig();
		ft_redir_all(cmd, lst);
		if (cmd->arg[0] == NULL)
			return (garbage_destroy(), 0);
        if (ft_path(env, cmd) == 1)
			return(garbage_destroy(), 1);
	    ft_execve(cmd, lst);
    }
    status = ft_wait_pids(*lst, status);
    ft_destroy_heredocs(lst);
    garbage_destroy();
	return (status);
}
