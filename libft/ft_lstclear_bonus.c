/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:38 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:52:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void del(void *content)
{
	g_free(content);
}*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	head = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		g_free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/*int main()
{
	t_list **head;
	t_list *a, *b, *c, *check;

	head = &a;
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	ft_lstclear(head, del);
	printf("%p\n", *head);
}*/