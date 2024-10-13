/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_vars_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:12:05 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/05 18:12:35 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_vals_dollar(t_var_replacer *vr, t_state *s)
{
	vr->nvv = pft_itoa(s->exit_code, s);
	vr->cut = 2;
	vr->i += ft_strlen(vr->nvv) - vr->cut;
}

void	set_vals_var(t_var_replacer *vr, t_state *s, char *str)
{
	vr->nvl = get_var_len(str, vr->i + 1);
	vr->cut = vr->nvl + 1;
	vr->nvv = get_var_value(&str[vr->i + 1], s->env, vr->nvl, s);
	vr->i += ft_strlen(vr->nvv) - vr->cut;
}

void	init_vr(t_var_replacer *vr)
{
	vr->sq = 0;
	vr->dq = 0;
	vr->i = 0;
	vr->nvv = NULL;
}
