/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:03:47 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 19:19:14 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
nvl : next var len
nvv : next var value
*/
typedef struct s_var_replacer
{
	int		i;
	int		i_save;
	int		sq;
	int		dq;
	int		nvl;
	int		cut;
	char	*nvv;
	int		x_join_all[2];
}			t_var_replacer;

typedef struct ms_append_helper
{
	int		i;
	char	sep;
}			t_msh;

typedef struct s_token_array_maker
{
	int		i;
	int		sq;
	int		dq;
	int		last_token_spe;
	int		next_quote;
	int		word_len;
	t_msh	msh;
}			t_am;

/*
libft with state
*/
char	*pft_strdup(const char *s1, t_state *state);
char	*pft_strjoin(char const *s1, char const *s2, t_state *state);
char	*pft_substr(char const *s, int start, int len, t_state *state);
char	*pft_itoa(int n, t_state *state);

/*
helpers.c
*/
int		array_len(t_token **array);
int		main_array_len(t_token ***array);
int		ft_is_space(char c);
void	set_quotes_mode(int *sq, int *dq, char c);

/*
pft_join_all.c
*/
char	*pft_join_all(char *line, char *var_value, int x[2], t_state *state);

/*
garbage_collector.c
*/
t_list	*new_gc(t_state *s);
void	*ft_malloc(size_t size, t_list **gc, t_state *s);
void	destroy_gc(t_list *gc);
void	shallow_clear_gc(t_list *gc, char **env);

/*
make_token_and_append.c
*/
t_token	**mt_append(int type, char *str, t_token **array, t_state *s);
t_token	**ms_append(char *line, t_token **array, t_state *s, t_msh msh);

/*
make_token_and_append_helpers.c
*/
int		cmd_present(t_token **array);
int		is_cmd(t_token **array);

/*
parsing_main.c
*/
void	ft_stx_err(char *str);
t_token	**make_token_array(char *line, t_token **token_array, t_state *s);
t_token	***parseline(t_state *s, char *line);

/*
parsing_main_helpers.c
*/
int		noquote(int sq, int dq);
int		get_next_quote(char *line, int start, int quote);
int		find_word_len(char *line, int i);
int		last_array_elem_valid(t_token **array);

/*
replace_vars.c
*/
int		is_regex(char c, int pos);
int		get_var_len(char *str, int start);
char	*get_var_value(char *str, char **env, int len, t_state *state);
char	*replace_vars(char *str, t_state *s);

/*
replace_vars_helpers.c
*/
void	set_vals_dollar(t_var_replacer *vr, t_state *s);
void	set_vals_var(t_var_replacer *vr, t_state *s, char *str);
void	init_vr(t_var_replacer *vr);

/*
split_array_tokens.c
*/
t_token	***ft_split_array_tokens(t_token **t_a, int type, t_state *s);

//////////////////////////////////
//    TO BIN :
//////////////////////////////////
void	print_token(t_token *token);
void	print_array(t_token **array);
void	print_main_array(t_token ***main_array);
