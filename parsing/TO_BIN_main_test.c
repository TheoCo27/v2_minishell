/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TO_BIN_main_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:28:07 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/22 23:49:07 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "../signal/ft_signal.h"

int g_signal = 0;

char	**make_envp(char **envp, t_state *s)
{
	char**array;

	if (envp)
		return(envp);
	array = ft_malloc(sizeof(char *), &(s->gc), s);
	if (!array)
		return (NULL);
	array[0] = NULL;
	return (array);
}

void	set_parent_exec_sig(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

t_state	*get_state(t_state *init)
{
	static t_state	*state = NULL;

	if (init != NULL)
		state = init;
	return (state);
}

int	minishell(t_state *state, t_token ***array)
{
	char	*line;

	line = readline("minishell> ");
	// set_exec_sig();
	if (!line)
		return (EXIT_FAILURE);
	add_history(line);
	array = parseline(state, line);
	if (array)
	{
		//print_main_array(array);
		set_parent_exec_sig();
		if (ft_make_exec(array, state) == EXIT_FAILURE)
			return (0);
	}
	// shallow_clear_gc(state.gc, state.env);
	if (state->exit_code == 128 + SIGQUIT)
		printf("Quit (core dumped)\n");
	else if (state->exit_code == 128 + SIGINT)
		printf("\n");
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_token	***array;
	t_state	state;

	// state = malloc(sizeof(t_state));
	// if (!state)
	// 	return (0);
	get_state(&state);
	state.exit_code = 0;
	state.test = 0;
	state.env = make_envp(envp, &state);
	state.gc = new_gc(&state);
	array = ft_malloc(sizeof(t_token **), &state.gc, &state);
	if (!array)
	{
		destroy_gc(state.gc);
		return(0);
	}
	while (1)
	{
		g_signal = 0;
		set_sig();
		if (minishell(&state, array) == EXIT_FAILURE)
			break;
		shallow_clear_gc(state.gc, state.env);
	}
	destroy_gc(state.gc);
	if (av || ac)
		return (0);
}

// pour compiler : cc -W... *.c libft/*.c -lreadline

// NO APPARENT ERRORS

// < infile cat -e | << limiter "hey" | wc -l | '                            ' | grep "$LANG       hehe"
// <infile cat -e|<<limiter"hey"|wc -l|'                            '|grep"$LANG       hehe"|$?
// echo "hehe         .         $?    $LANG""''''''"'"""""""'|<infile<infile<infile


// int	main(int ac, char **av, char **envp)
// {
// 	t_token	***array;
// 	t_state	*state;
// 	char	*line;

// 	state = malloc(sizeof(t_state));
// 	if (!state)
// 		return (0);
// 	state->exit_code = 999;
// 	state->env = &(*(envp));
// 	state->gc = new_gc(state);
// 	array = ft_malloc(sizeof(t_token **), &(state->gc), state);
// 	if (!array)
// 	{
// 		destroy_gc(state->gc);
// 		free(state);
// 		return(0);
// 	}
// 	line = readline("minishell> ");
// 	array = parseline(state, line);
// 	if (array)
// 	{
// 		print_main_array(array);
// 		ft_make_exec(array, envp);
// 	}
// 	else
// 		printf("Array is NULL\n");
// 	shallow_clear_gc(state->gc, state->env);
// 	shallow_clear_gc(state->gc, state->env);
// 	shallow_clear_gc(state->gc, state->env);
// 	shallow_clear_gc(state->gc, state->env);
// //	int	i = 0;
// 	// while (state->env[i])
// 	// {
// 	// 	ft_putendl_fd(state->env[i], 1);
// 	// 	i++;
// 	// }
// 	destroy_gc(state->gc);
// 	free(state);
// 	if (av || ac)
// 		return (0);
// }