/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:49 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/12 16:48:24 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}

/*int main()
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list	*head;
	t_list *check;
	int i = 420, j = 8, k = 27;
	a = ft_lstnew(&i);
	b = ft_lstnew(&j);
	c = ft_lstnew(&k);
	head = a;
	a->next = b;
	b->next = c;
	c->next = NULL;
	

	check = ft_lstlast(head);
	printf ("%d\n", (*(int *)check->content));
}*/