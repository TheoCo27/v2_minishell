/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:57 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/18 18:12:57 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec/pipex.h"
#include <signal.h>

void	check_if_sig(void);
void	set_sig(void);
void	set_heredoc_sig(void);
void	set_exec_sig(void);