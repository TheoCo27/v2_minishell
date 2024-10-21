/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:44:50 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/21 20:56:12 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


// int	ft_make_exec(int argc, char **argv, char **env)
// {
// 	t_info_exec	*lst;
// 	int			status;

// 	status = 0;
// 	ft_check_argc(argc);
// 	lst = NULL;
// 	lst = ft_make_pipelst(argv);
// 	if (!lst)
// 		return (1);
// 	if (ft_pipelst_size(lst) == 1)
//         return (status = ft_only_child(lst, env, &lst), status);//gestion leaks a part a faire
// 	ft_set_pipes(&lst);
// 	ft_while_fork(&lst, env);
// 	if (ft_pipelst_size(lst) > 1)
//     	ft_close_allpipes(lst);
//     status = ft_wait_pids(lst, status);
//     ft_pipelst_clear(&lst);
// 	return (status);
// }

// ici print only
// int	ft_make_exec(t_token ***cmd_array, char **env)
// {
// 	t_info_exec	*lst;
// 	int			status;

// 	status = 0;
// 	lst = NULL;
// 	lst = ft_make_pipelst(cmd_array);
// 	ft_name_heredocs(&lst);
// 	ft_pipelst_printcmd(&lst);
// 	(void)env;
// 	return (status);
// }

// GOOOD FUNCTIION HERE
int	ft_make_exec(t_token ***cmd_array, t_state *state)
{
	t_info_exec	*lst;
	int			status;

	status = 0;
	lst = NULL;
	lst = ft_make_pipelst(cmd_array, state);
	if (!lst)
		return (1); // leaks all good till here
	if (ft_name_heredocs(&lst) == -1)
		return (garbage_destroy(), 1); // leaks all good till here
	if (ft_fill_all_heredocs(&lst) == -1)
		return (garbage_destroy(), 1);
	//ft_pipelst_printcmd(&lst); // leaks all good till here
	if (ft_pipelst_size(lst) == 1)
        return (status = ft_only_child(lst, state->env, &lst), status);//leaks all good till here
	if (ft_set_pipes(&lst) == -1)
		return (garbage_destroy(), 1); //leaks all good till here
	if (ft_while_fork(&lst, state->env) == -1)
	{
		status = ft_wait_pids(lst, status);
		ft_close_allpipes(lst);
		garbage_destroy();
		return (status);
	}
	if (ft_pipelst_size(lst) > 1)
    	ft_close_allpipes(lst);
    status = ft_wait_pids(lst, status);
	ft_destroy_heredocs(&lst);
    garbage_destroy();
	return (status);
}

// static void	ft_exit(int fork_nb, int pid1, int fd[2])
// {
// 	if (fork_nb == 0)
// 	{
// 		ft_close_pipe(fd);
// 		perror("fork pid[0] failed");
// 		exit(1);
// 	}
// 	if (fork_nb == 1)
// 	{
// 		ft_close_pipe(fd);
// 		perror("fork pid[1] failed");
// 		waitpid(pid1, NULL, 0);
// 		exit(2);
// 	}
// }


//test doublement chaîné
// int main(int argc, char **argv, char **env)
// {
// 	t_info_exec	*lst;
// 	t_info_exec	*cmd;
// 	size_t		lst_size;

// 	ft_check_argc(argc);
//  	lst = NULL;
//  	lst = ft_make_pipelst(argv);
//  	if (!lst)
//  		return (1);
//  	lst_size = ft_pipelst_size(lst);
// 	ft_pipelst_reverse_printcmd(&lst);


// int main(int argc, char **argv, char **env)
// {
// 	return (ft_make_exec(argc, argv, env));
// }


// int main(int argc, char **argv)
// {
// 	t_info_exec	*lst;

// 	ft_check_argc(argc);
// 	lst = ft_make_pipelst(argv);
// 	ft_pipelst_printcmd(&lst);
// 	ft_pipelst_clear(&lst);
// 	return (0);
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_info_exec	cmd[2];
// 	int			fd[2];
// 	int			pid[2];

// 	ft_check_argc(argc);
// 	ft_pipe(fd);
// 	ft_set_cmds(&cmd[0], &cmd[1], fd, env);
// 	pid[0] = fork();
// 	if (pid[0] < 0)
// 		ft_exit(0, pid[0], fd);
// 	if (pid[0] == 0)
// 		ft_first_child(argv, env, fd, &cmd[0]);
// 	pid[1] = fork();
// 	if (pid[1] < 0)
// 		ft_exit(1, pid[0], fd);
// 	if (pid[1] == 0)
// 		ft_2nd_child(argv, env, fd, &cmd[1]);
// 	ft_close_pipe(fd);
// 	ft_wait_pids(pid[0], pid[1]);
// 	return (0);
// }
