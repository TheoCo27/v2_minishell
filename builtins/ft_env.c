/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:52 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/08 15:20:46 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **env)
{
	while (env && *env)
	{
		ft_putendl_fd(*env, 1);
		env++;
	}
	return (0);
}

/* int	main(int ac, char **av, char **envp)
{
	ft_env(envp);
	if (ac || av)
		return (0);
} */
