/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:17:42 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/17 22:53:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int in_heredoc(int update)
{
	static int in_heredoc;

	if (update == 1)
		in_heredoc = 1;
	if (update == -1)
		in_heredoc = 0;
	return (in_heredoc);
}
