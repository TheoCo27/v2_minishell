/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:43 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:52:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void del(void *content)
{
	if(content)
		g_free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	g_free(lst);
}

/*int main()
{
	t_list *new;
	t_list *a, *b, *c, *check;

	new = ft_lstnew(ft_strdup("hey"));
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	a->next = b->next;
	ft_lstdelone(b, del);
	check = a->next;
	printf("%s\n", (char *)check->content);
}*/