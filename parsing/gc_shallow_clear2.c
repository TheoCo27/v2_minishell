/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_shallow_clear2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:45:47 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/24 19:33:38 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	env_or_in_env(void *elem, char **env)
{
	if (elem == env)
		return (1);
	while (*(env))
	{
		if (*(env) == elem)
			return (1);
		(env)++;
	}
	return (0);
}

static void	set_and_free(t_list **gc, t_list **ptr, t_list **prev)
{
	if (*prev == NULL)
		*gc = (*ptr)->next;
	else
		(*prev)->next = (*ptr)->next;
	free((*ptr)->content);
	(*ptr)->content = NULL;
	free(*ptr);
	*ptr = NULL;
}

void	shallow_clear2(t_list **gc, char **env)
{
	t_list	*ptr;
	t_list	*prev;

	if (!gc)
		return ;
	ptr = *gc;
	prev = NULL;
	while (ptr)
	{
		if (ptr->content && env_or_in_env(ptr->content, env) == 0)
			set_and_free(gc, &ptr, &prev);
		else
			prev = ptr;
		if (prev)
			ptr = prev->next;
		else
			ptr = *gc;
	}
}
