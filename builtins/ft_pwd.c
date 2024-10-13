/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                         	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:17:24 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/07 17:03:15 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(t_state *s)
{
	char	dir[PATH_MAX];

	if (getcwd(dir, PATH_MAX))
	{
		ft_putendl_fd(dir, 1);
		return (0);
	}
	ft_putendl_fd("pwd: error retrieving current directory", 2);
	(void)s;
	return (1);
}

/* int	main(void)
{
	t_state *s;
	s = malloc(sizeof(t_state));
	s->exit_code = 999;
	ft_pwd(s);
} */
