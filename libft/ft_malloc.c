/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:15:14 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 16:23:47 by tcohen           ###   ########.fr       */
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

t_garbage *get_garbage(t_garbage *update)
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
	return (head);
}

void	*g_malloc(size_t size)
{
	t_garbage	*new;
	t_garbage	*lst;

	lst = get_garbage(NULL);
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
