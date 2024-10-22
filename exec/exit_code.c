/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:15:53 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/22 22:34:55 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	errno_to_exit_code(int errno_value)
{
	if (errno_value == 0)
		return (0);
	if (errno_value == ENOENT)
		return (127);
	if (errno_value == EACCES)
		return (126);
	else
		return (1);	
}