/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vispinos <vispinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:39:55 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/09 14:16:47 by vispinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_echo(char **array)
{
	int	i;
	int	add_endline;

	if (sal(array) < 2)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	add_endline = 1;
	if (ft_strncmp(array[1], "-n", 2) == 0)
		add_endline = 0;
	i = 2 - add_endline;
	while (array[i])
	{
		if (ft_strlen(array[i]) != 0)
			ft_putstr_fd(array[i], 1);
		if (array[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (add_endline != 0)
		ft_putchar_fd('\n', 1);
	return (0);
}

/* int	main(int ac, char **av)
{
	// In test : './a.out' stands for echo (ex: ./a.out "Hello" == exit "Hello")
	ft_echo(av);
	if (ac)
		return (0);
} */
