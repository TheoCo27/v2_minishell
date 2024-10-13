/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:54:31 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/12 16:46:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list a;
	t_list b;
	t_list c;
	t_list *pa;

	pa = NULL;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	
	printf("%d\n", ft_lstsize(pa));
}*/