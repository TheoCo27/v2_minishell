/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:45:15 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 18:14:13 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_regex(char c, int pos)
{
	if ((ft_isdigit(c) && pos > 0) || ft_isalpha(c) || c == '_')
		return (1);
	else
		return (0);
}

int	get_var_len(char *str, int start)
{
	int	i;

	i = 0;
	while (str[i + start] && is_regex(str[i + start], i))
		i++;
	return (i);
}

char	*get_var_value(char *str, char **env, int len, t_state *state)
{
	char	*value;
	int		i;

	value = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(str, env[i], len) == 0
			&& env[i][len] == '=')
		{
			value = pft_strdup(&(env[i][len + 1]), state);
		}
		i++;
	}
	return (value);
}

char	*replace_vars(char *str, t_state *s)
{
	t_var_replacer	vr;

	init_vr(&vr);
	while (str[vr.i])
	{
		vr.i_save = vr.i;
		set_quotes_mode(&vr.sq, &vr.dq, str[vr.i]);
		if (vr.sq == 1 || str[vr.i] != '$' || !str[vr.i + 1]
			|| (!is_regex(str[vr.i + 1], 0) && str[vr.i + 1] != '?'))
			vr.i++;
		else
		{
			if (str[vr.i + 1] == '?')
				set_vals_dollar(&vr, s);
			else
				set_vals_var(&vr, s, str);
			vr.x_join_all[0] = vr.i_save;
			vr.x_join_all[1] = vr.cut;
			str = pft_join_all(str, vr.nvv, vr.x_join_all, s);
			if (!str)
				return (NULL);
		}
	}
	return (str);
}
