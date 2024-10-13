#include "parsing.h"
#include <readline/readline.h>
#include <readline/history.h>


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
int	main(int ac, char **av, char **envp)
{
	t_token	***array;
	t_state	*state;
	char	*line;

	state = malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->exit_code = 999;
	state->env = &(*(envp));
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
		line = readline("minishell> ");
		if (ft_strncmp(line, "stop", 4) == 0)
			break;
		add_history(line);
		array = parseline(state, line);
		if (array)
		{
			print_main_array(array);
			ft_make_exec(array, envp);
		}
		else
			printf("Array is NULL\n");
	}
	shallow_clear_gc(state->gc, state->env);
	shallow_clear_gc(state->gc, state->env);
	shallow_clear_gc(state->gc, state->env);
	shallow_clear_gc(state->gc, state->env);
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
