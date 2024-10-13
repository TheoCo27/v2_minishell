/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:20 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/12 16:45:14 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	last = *lst;
	last = ft_lstlast(last);
	last->next = new;
}

/*int main()
{
	t_list *new;
	t_list **head;
	t_list *a, *b, *c;
	t_list	*check;

	new = ft_lstnew("hey");
	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");

	head = &a;
	a->next = b;
	b->next = c;
	c->next = NULL;

	ft_lstadd_back(head, new);
	check = c->next;
	printf("%s\n", (char *)check->content);
}*/