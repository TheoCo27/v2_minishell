/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:51:13 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/18 16:11:05 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include "../minishell.h"
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_file
{
	char			type;
	char			*name;
	char			*delimiter;
	char			**heredoc_content;
	struct	s_file	*next;
}					t_file_lst;

typedef struct s_heredoc
{
	char	*heredoc_name;
	int		fd_heredoc;
}			t_heredoc;

typedef struct s_info_exec
{
	char	*cmd;
	char	*path;
	char	**t_path;
	char	**arg;
	int		pipe_fd[2];
	int		in_fd;
	int		out_fd;
	t_file_lst	*file_lst;
	char	**env;
	size_t	index;
	int		pid;
	t_state *state;
	struct s_info_exec *next;
	struct s_info_exec *prev;
}			t_info_exec;

//ft_sig.c
int in_heredoc(int update);
// ft_file_lst.c
t_file_lst	*ft_newfile(char *content, char type);
t_file_lst	*ft_filelast(t_file_lst *lst);
void	ft_fileadd_back(t_file_lst **lst, t_file_lst *new);
void	ft_filelstclear(t_file_lst **lst);
void    ft_print_filelst(t_file_lst **lst);

//ft_heredoc.c
int	ft_name_heredocs(t_info_exec **lst);
t_heredoc *ft_make_heredoc(t_info_exec *cmd, t_info_exec **lst);
int ft_destroy_heredocs(t_info_exec **lst);
int ft_fill_heredoc(t_file_lst *file, t_info_exec *cmd, t_info_exec **lst);
int ft_fill_all_heredocs(t_info_exec **lst);

//ft_make_exec.c
//int	ft_make_exec(int argc, char **argv, char **env);
int	ft_make_exec(t_token ***cmd_array, t_state *state);

//ft_child.c
// int		ft_cmd_arg(char *cmd, t_info_exec *info, t_info_exec **lst);
int		ft_exec_child(t_info_exec *cmd, t_info_exec **lst, char **env, int status);
int     ft_close_wrongpipes(t_info_exec *cmd, t_info_exec **lst);

//ft_path.c
int		ft_getenv_path(char **env, t_info_exec *info);
int		ft_check_ifpath(t_info_exec *info);
int		ft_find_cmd(t_info_exec *info);
int		ft_path(char **env, t_info_exec *info);

//ft_secure.c
int		ft_open(char *file_name, char mode, t_info_exec *info, t_info_exec **lst);
int		ft_dup2(int old_fd, int new_fd);
int		ft_execve(t_info_exec *cmd, t_info_exec **lst);
int		ft_pipe(int fd[2], t_info_exec	**lst, t_info_exec *cmd);
int		ft_fork(t_info_exec *cmd, t_info_exec **lst);
// ft_all.c
void	ft_close_pipe(int pipe_fd[2]);
void	ft_close_all(int pipe_fd[2], int in_out_fd);
int		ft_wait_pids(t_info_exec *lst, int status);
int		ft_clean_info(t_info_exec *cmd);
//ft_check.c
void	ft_check_argc(int argc);
void	ft_check_argv(char *cmd, int fd[2]);
int		ft_check_if_alpha(char *str);
int is_directory(const char *path);
//ft_set.c
int		ft_execve_stuff(t_info_exec *info);
// ft_pipe_lst.c
//t_info_exec	*ft_pipelst_new(char *cmd);
t_info_exec	*ft_pipelst_new(void);
t_info_exec	*ft_pipelst_last(t_info_exec *lst);
void	ft_pipelst_addback(t_info_exec **lst, t_info_exec *new);
void	ft_pipelst_clear(t_info_exec **lst);
void	ft_pipelst_printcmd(t_info_exec	**lst);
void	ft_pipelst_reverse_printcmd(t_info_exec	**lst);
t_info_exec	*ft_make_pipelst(t_token ***array, t_state *state);
size_t	ft_pipelst_size(t_info_exec *lst);
void	ft_pipelst_clear_node(t_info_exec *node);
//ft_exec_one.c
int	ft_only_child(t_info_exec *cmd, char **env, t_info_exec **lst);
//ft_while_cmd.c
int     ft_close_allpipes(t_info_exec  *lst);
int    ft_set_pipes(t_info_exec **lst);
int		ft_while_fork(t_info_exec **lst_cmd, char **env);
int		ft_close_remaining_pipes(t_info_exec *cmd, t_info_exec **lst);
//ft_token_to_exec.h
t_info_exec *ft_token_to_exec(t_token **array);
t_info_exec *ft_convert_redir_token(t_info_exec *cmd, t_token **array, int *i);
//ft_redir.c
int ft_redir_all(t_info_exec *cmd, t_info_exec **lst);


#endif