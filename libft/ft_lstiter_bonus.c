/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:46 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/12 16:04:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void upc(void *content)
{
	char *temp;

	temp = (char *)content;
	*temp = *temp -32;
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	while (lst)
	{
		temp = lst->next;
		f(lst->content);
		lst = temp;
	}
}

/*int main()
{
	t_list *a, *b, *c;
	
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	ft_lstiter(a, upc);
	printf("%s\n", (char *)a->content);
	printf("%s\n", (char *)b->content);
	printf("%s\n", (char *)c->content);
}*/