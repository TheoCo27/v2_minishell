/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:11:30 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/12 16:46:39 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main()
{
	t_list *ptr;
	t_list	**head;
	t_list	new;
	int  test = 4, test2 = 5, test3 = 6;
	
	head = &ptr;
	ptr = ft_lstnew(&test);
	ptr->next = ft_lstnew(&test2);
	ptr->next->next = NULL;
	new.next = 	NULL;

	printf("new content : %d\n", *((int *)ptr->content));
	ft_lstadd_front(head, ft_lstnew(&test3));
	printf("new content : %d\n", *((int *)ptr->content));
}*/