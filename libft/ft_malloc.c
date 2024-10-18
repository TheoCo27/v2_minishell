/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:15:14 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/16 17:15:25 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_garbage *set_garbage(void)
{
	t_garbage *head;

	head = garbage_lstnew();
	if (!head)
		return (NULL);
	return (head);
}

t_garbage *get_garbage(t_garbage *update, int reset)
{
	static t_garbage *head;

	if (head == NULL)
	{
		head = set_garbage();
		if (!head)
			return (NULL);
	}
	if (update != NULL)
		head = update;
	if (reset == 1)
		head = NULL;
	return (head);
}

void	*g_malloc(size_t size)
{
	t_garbage	*new;
	t_garbage	*lst;

	lst = get_garbage(NULL, 0);
	if (!lst)
		return (NULL);
	new = garbage_lstnew();
	if (!new)
		return (garbage_lstclear(&lst), NULL);
	garbage_lstaddback(new, &lst);
	new->content = malloc(size);
	if (!new->content)
		return (garbage_lstclear(&lst), NULL);
	return (new->content);
}

void	garbage_destroy(void)
{
	t_garbage *lst;

	lst = get_garbage(NULL, 0);
	if (!lst)
		return;
	garbage_lstclear(&lst);
	get_garbage(NULL, 1);
}