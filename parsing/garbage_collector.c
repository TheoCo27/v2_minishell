/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:34 by vispinos          #+#    #+#             */
/*   Updated: 2024/10/10 19:29:39 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*new_gc(t_state *s)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
	{
		ft_putendl_fd("minishell: malloc failed", 2);
		return (s->exit_code = 1, NULL);
	}
	list->content = NULL;
	list->next = NULL;
	return (list);
}

void	*ft_malloc(size_t size, t_list **gc, t_state *s)
{
	t_list	*lst_elem;

	lst_elem = malloc(sizeof(t_list));
	if (!lst_elem)
	{
		ft_putendl_fd("minishell: malloc failed", 2);
		return (s->exit_code = 1, NULL);
	}
	lst_elem->content = malloc(size);
	if (!lst_elem->content)
	{
		ft_putendl_fd("minishell: malloc failed", 2);
		return (s->exit_code = 1, free(lst_elem), NULL);
	}
	lst_elem->next = *gc;
	*gc = lst_elem;
	return (lst_elem->content);
}

void ft_free(void *ptr, t_list **gc)
{
	t_list *temp;

	if (!ptr)
		return ;
	temp = *gc;
	while(temp)
	{
		if (temp->content == ptr)
		{
			free(ptr);
			ptr = NULL;
			return;
		}
		temp = temp->next;	
	}
}

void	destroy_gc(t_list *gc)
{
	if (!gc)
		return ;
	destroy_gc(gc->next);
	if (gc->content)
		free(gc->content);
	free(gc);
}

void	shallow_clear_gc(t_list *gc, char **env)
{
	if (!gc)
		return ;
	shallow_clear_gc(gc->next, env);
	if (!(gc->content))
		return ;
	if (gc->content == env)
		return ;
	while (*(env))
	{
		if (*(env) == gc->content)
			return ;
		(env)++;
	}
	free(gc->content);
	gc->content = NULL;
}
