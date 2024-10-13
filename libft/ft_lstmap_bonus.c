/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:53 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/13 19:52:06 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void del(void *content)
{
	if(content)
		g_free(content);
}
void *upc(void *content)
{
	char *temp;

	temp = (char *)content;
	*temp = *temp -32;
	return (content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*tmp_content;

	new_list = NULL;
	while (lst)
	{
		tmp_content = f(lst->content);
		new_obj = ft_lstnew(tmp_content);
		if (!new_obj)
		{
			del(tmp_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}

/*int main()
{
	t_list *a, *b, *c, *check;

	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	check = ft_lstmap(a, upc, del);
	while (check)
	{
		printf("%s\n", (char *)check->content);
		check = check->next;
		
	}
}*/