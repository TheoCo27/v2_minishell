/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:41:57 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 11:41:00 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_export_zero(t_state *s)
{
	char	**temp_env;
	int		i;

	temp_env = char_star_array_sort(s->env, s);
	if (!temp_env || !*temp_env)
		return (1);
	i = 0;
	while (temp_env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(temp_env[i], 1);
		i++;
	}
	return (0);
}

int	unvalid_regex(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	str = &str[i];
	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && i != 0)
			return (0);
		if (!is_regex(str[i], i))
			return (1);
		i++;
	}
	return (0);
}

char	**append_char_star(char **array, char *str, t_state *s)
{
	int		len;
	int		i;
	char	**new_array;

	len = sal(array);
	new_array = ft_malloc(sizeof(char *) * (len + 2), &(s->gc), s);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = str;
	new_array[i + 1] = NULL;
	return (new_array);
}

int	ft_export(char **vars, t_state *s)
{
	int		i;
	int		code;
	char	*var_name;

	if (sal(vars) == 0)
		return (ft_export_zero(s));
	code = 0;
	i = 0;
	while (i < sal(vars))
	{
		if (unvalid_regex(vars[i]))
		{
			ft_putstr_fd("bash: export: '", 2);
			ft_putstr_fd(vars[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			code = 1;
			i++;
			continue ;
		}
		var_name = pft_substr(vars[i], 0, get_var_len(vars[i], 0), s);
		ft_unset(make_char_s_arr_from_str(var_name, s), s);
		s->env = append_char_star(s->env, vars[i], s);
		if (!s->env)
			return (1);
		i++;
	}
	return (code);
}

/* int main(int ac, char **av, char **envp)
{
	t_state *s;
	char	**export_param;

	s = malloc(sizeof(t_state));
	s->exit_code = 999;
	s->gc = new_gc(s);
	s->env = envp;
	// test for case NULL
	// export_param = NULL;
	// ft_export(export_param, s);
	// if (ac || av)
	// 	return (0);
	// end test NULL
	export_param = malloc(sizeof(char *));
	export_param = make_char_s_arr_from_str("EXPORT_MINISHELL1=12", s);
	export_param = append_char_star(export_param, "&WRONG_EXPORT", s);
	export_param = append_char_star(export_param, "1WRONG_EXPORT", s);
	export_param = append_char_star(export_param,"EXPORT_MINISHELL2=120", s);
	export_param = append_char_star(export_param, "a", s);
	export_param = append_char_star(export_param, "WRONG-EXPORT", s);
	export_param = append_char_star(export_param,
					"_EXPORT_MINI5SHELL4=120", s);
	export_param = append_char_star(export_param,
					"_EXPORT_MINI5SHELL4='heeeeeeeeee'", s);
	export_param = append_char_star(export_param,"_EXPORT_MINI5SHELL4=2", s);
	export_param = append_char_star(export_param,
					"_EXPORT_MINI5SHELL4=aaaaaaa aaaaaaaa aaaa", s);
	export_param = append_char_star(export_param,"_EXPORT_MINI5SHELL5", s);
	export_param = append_char_star(export_param,"_EXPORT_MINI5SHELL6=", s);
	export_param = append_char_star(export_param,"_EXPORT_MINI5SHELL6=''", s);
	export_param = append_char_star(export_param,
					"_EXPORT_MINI5SHELL6=\"\"", s);
	export_param = append_char_star(export_param, "WRO-NG_EXPORT", s);
	export_param = append_char_star(export_param, "WRONG_E'XPORT", s);
	export_param = append_char_star(export_param, "$WRONG_EXPORT", s);
	export_param = append_char_star(export_param, "", s);
	export_param = append_char_star(export_param, "\"\"", s);
	export_param = append_char_star(export_param, "''", s);
	export_param = append_char_star(export_param, "\"\"=aaaaaaaaa", s);
	export_param = append_char_star(export_param, "''", s);
	export_param = append_char_star(export_param,
					"''=aa bb gg 'eezzeezzee' aaaaa", s);
	export_param = append_char_star(export_param,
				"_EXPORT_MINI5SHELL7='abcdefg mmmmm lllll mmmmm lllll'", s);
	ft_export(export_param, s);
	ft_env(s->env);
	if (ac || av)
		return (0);
} */
