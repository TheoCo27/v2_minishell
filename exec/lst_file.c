/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:09:25 by theog             #+#    #+#             */
/*   Updated: 2024/10/13 20:33:51 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_file_lst	*ft_newfile(char *content, char type)
{
	t_file_lst	*new;

	new = (t_file_lst *)g_malloc(sizeof(t_file_lst));
	if (!new)
		return (NULL);
    new->type = type;
	new->next = NULL;
    if (type != 'h')
	    new->name = content;
    if (type == 'h')
    {
        new->name = NULL;
        new->delimiter = content;
    }
	return (new);
}

t_file_lst	*ft_filelast(t_file_lst *lst)
{
	t_file_lst	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	ft_fileadd_back(t_file_lst **lst, t_file_lst *new)
{
	t_file_lst	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = ft_filelast(last);
	last->next = new;
}

void	ft_filelstclear(t_file_lst **lst)
{
	t_file_lst	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
        //g_free ce que y a g_free
		g_free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void    ft_print_filelst(t_file_lst **lst)
{
    t_file_lst *temp;

    temp = (*lst);
    while(temp)
    {
        if (temp->name)
            printf("file name: %s\n", temp->name);
        if (temp->delimiter)
            printf("file delimiter: %s\n", temp->delimiter);
        if (temp->type)
            printf("file type: %c\n", temp->type);
        temp = temp->next;
    }
}