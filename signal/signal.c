/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:12:07 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/18 18:59:19 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
# include <readline/readline.h>
# include <readline/history.h>

// static void	sig_handler(int sig)
// {
// 	(void)sig;
// 	if (in_heredoc(0) == 0)
// 	{
// 		write(2, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	if (in_heredoc(0) == 1)
// 	{
// 		//close(heredoc_fd);
// 		garbage_destroy();
// 		in_heredoc(-1);
// 	}
// }

static void	sig_handler(int sig)
{
	g_signal = sig;

	check_if_sig();
}

void	check_if_sig(void)
{
	if (in_heredoc(0) == 0 && g_signal == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal = 0;
}

void	set_sig(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

static void heredoc_sig_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 2);
}

void	set_heredoc_sig(void)
{
	signal(SIGINT, heredoc_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	exec_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		//rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (Core dumped)\n", 2);
	}
}
void	set_exec_sig(void)
{
	signal(SIGINT, exec_sig_handler);
	signal(SIGQUIT, exec_sig_handler);
}
