/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TO_BIN_main_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:28:07 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/18 18:17:19 by tcohen           ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	t_token	***array;
	t_state	*state;
	char	*line;

	state = malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->exit_code = 999;
	state->env = make_envp(envp, state);
	state->gc = new_gc(state);
	array = ft_malloc(sizeof(t_token **), &(state->gc), state);
	if (!array)
	{
		destroy_gc(state->gc);
		free(state);
		return(0);
	}
	while (1)
	{
		set_sig();
		line = readline("minishell> ");
		set_exec_sig();
		if (line == NULL)
			break;
		if (ft_strncmp(line, "stop", 4) == 0)
			break;
		add_history(line);
		array = parseline(state, line);
		if (array)
		{
			//print_main_array(array);
			ft_make_exec(array, state);
			shallow_clear_gc(state->gc, state->env);
		}
		else
			shallow_clear_gc(state->gc, state->env);
	}
	destroy_gc(state->gc);
	free(state);
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