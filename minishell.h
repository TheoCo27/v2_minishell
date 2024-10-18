/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:02:09 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/17 23:04:44 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h" // will need to remove after code sync
# include "stdio.h"

# define LEXICAL
# define INFILE 1
# define HEREDOC 2
# define OUTFILE_TRUNCATE 3
# define OUTFILE_APPEND 4
# define PIPE 5
# define CMD 6
# define ARG 7

# define QUOTES
# define SQUOTE 39
# define DQUOTE 34
# define NOQUOTE_SEP 0

extern int g_signal;

typedef struct s_state
{
	char	**env;
	int		exit_code;
	t_list	*gc;
}			
	t_state;


typedef struct s_token
{
	int		type;
	char	*content;
	int		is_special;
}			t_token;

int		ft_make_exec(t_token ***cmd_array, t_state *state);
int		launch_if_builtin(char **array, t_state *s);
#endif