/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:02 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 11:37:58 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_join_key_value(char *str1, char *str2, t_state *s)
{
	char	*str;
	char	**array;

	str = pft_strjoin(str1, "=", s);
	if (!str)
		return (NULL);
	str = pft_strjoin(str, str2, s);
	if (!str)
		return (NULL);
	array = make_char_s_arr_from_str(str, s);
	if (!array)
		return (NULL);
	return (str);
}

int	ft_cd(char **array, t_state *s)
{
	char	absolute_dest[PATH_MAX];
	char	**export_param;
	char	*str;

	if (chdir(array[1]) != 0)
	{
		// voir si Théo veut + pousser l'exec / la gestion des erreurs
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putendl_fd(array[1], 2);
		return (1);
	}
	getcwd(absolute_dest, PATH_MAX);
	str = (ft_join_key_value("OLDPWD", get_var_value("PWD", s->env, 3, s), s));
	export_param = make_char_s_arr_from_str(str, s);
	if (!export_param)
		return (1);
	str = ft_join_key_value("PWD", absolute_dest, s);
	export_param = append_char_star(export_param, str, s);
	if (!export_param)
		return (1);
	ft_export(export_param, s);
	return (0);
}

/* int	main(int ac, char **av, char **envp)
{
	t_state	*s;

	s = malloc(sizeof(t_state));
	s->exit_code = 999;
	s->gc = new_gc(s);
	s->env = envp;
	ft_cd(av, s);
	ft_export_zero(s);
	if (ac)
		return (0);
} */
