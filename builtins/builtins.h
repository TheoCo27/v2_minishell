/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:57:29 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 19:58:11 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <limits.h>
# include "../parsing/parsing.h"
# include "../minishell.h"

# define CD 0
# define ECHO 1
# define ENV 2
# define EXIT 3
# define EXPORT 4
# define PWD 5
# define UNSET 6

int		ft_echo(char **array);
int		ft_env(char **env);
int		ft_exit(char **array, t_state *s);
int		ft_pwd(t_state *s);

/* detect_and_launch.c */
int		launch_if_builtin(char **array, t_state *s);

/* ft_cd.c */
int		ft_cd(char **array, t_state *s);
char	*ft_join_key_value(char *str1, char *str2, t_state *s);
//char	*ft_export_key_value(char *str1, char *str2, t_state *s);

/* ft_export.c */
int		unvalid_regex(char *str);
int		ft_export_zero(t_state *s);
char	**append_char_star(char **array, char *str, t_state *s);
int		ft_export(char **vars, t_state *s);

/* ft_export_helpers.c */
char	**char_star_array_sort(char **array, t_state *s);
char	**make_char_s_arr_from_str(char *str, t_state *s);

/* ft_unset.c */
/* sal -> string array len */
int		sal(char **array);
int		is_present(char *env_elem, char **vars);
int		ft_unset(char **vars, t_state *s);

#endif
