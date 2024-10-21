/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:12:07 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/21 21:20:50 by tcohen           ###   ########.fr       */
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

int	sig_event(void)
{
	return (EXIT_SUCCESS);
}
t_state	*get_state(t_state *init);

static void	sig_handler(int sig)
{
	g_signal = 128 + sig;
	// rl_event_hook = sig_event;
	if (sig == SIGINT)
		get_state(NULL)->exit_code = 128 + SIGINT;
	check_if_sig();
}

void	check_if_sig(void)
{
	if (in_heredoc(0) == 0 && g_signal == 128 + SIGINT)
	{
		// rl_replace_line("", 0);
		rl_done = 1;
		// write(2, "\n", 1);
		// rl_on_new_line();
		// rl_redisplay();
		// printf("\n");
	}
	// g_signal = 0;
}

void	set_sig(void)
{
	rl_event_hook = sig_event;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

static void heredoc_sig_handler(int sig)
{
	g_signal = 128 + sig;
	//rl_done = 1;
	// close(0);
	get_state(NULL)->exit_code = 128 + sig;
	// if (sig ==  SIGINT)
	// {
	// 	rl_replace_line("", 0);
	rl_done = 1;
	// 	write(2, "\n", 1);
	// 	rl_on_new_line();
	// 	// printf("\n");
	// }
	// ft_putstr_fd("\n", 2);
}

void	set_heredoc_sig(void)
{
	rl_event_hook = sig_event;
	signal(SIGINT, heredoc_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

// static void	exec_sig_handler(int sig)
// {
// 	//rl_event_hook = sig_event;
// 	if (sig == SIGINT)
// 	{
// 		if (in_heredoc(0) == 1)
// 		{
// 			close(STDIN_FILENO);
// 			g_signal = 5;
// 			return;
// 		}
// 		write(2, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		//rl_redisplay();
// 	}
// 	if (sig == SIGQUIT)
// 	{
// 		ft_putstr_fd("Quit (Core dumped)\n", 2);
// 	}
// }

void	set_exec_sig(void)
{
	// signal(SIGINT, exec_sig_handler);
	// signal(SIGQUIT, exec_sig_handler);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_IGN);
}
