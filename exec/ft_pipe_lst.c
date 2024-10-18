/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:09:56 by tcohen            #+#    #+#             */
/*   Updated: 2024/10/16 16:29:27 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_info_exec	*ft_pipelst_new(void)
{
	t_info_exec	*new;

	new = (t_info_exec *)g_malloc(sizeof(t_info_exec));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_info_exec));
	new->cmd = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->pid = -1;
	new->file_lst = NULL;
	new->arg = ft_make_tabstr();
	if (!new->arg)
		return (g_free(new), NULL);
	return (new);
}

// t_info_exec	*ft_pipelst_new(void)
// {
// 	t_info_exec	*new;

// 	new = (t_info_exec *)malloc(sizeof(t_info_exec));
// 	if (!new)
// 		return (NULL);
// 	ft_bzero(new, sizeof(t_info_exec));
// 	new->cmd = NULL;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	new->pid = -1;
// 	return (new);
// }

t_info_exec	*ft_pipelst_last(t_info_exec *lst)
{
	t_info_exec	*tmp;

	tmp = lst;
	while(tmp)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_pipelst_addback(t_info_exec **lst, t_info_exec *new)
{
	t_info_exec	*last;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = ft_pipelst_last(*lst);
	last->next = new;
	new->prev = last;
}

void	ft_pipelst_clear_node(t_info_exec *node)
{
	if (node->cmd)
		g_free(node->cmd);
	if (node->arg)
		ft_free_all(node->arg);
	if (node->file_lst)
		ft_filelstclear(&node->file_lst);
	g_free(node);
}

void	ft_pipelst_clear(t_info_exec **lst)
{
	t_info_exec	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		//ici free le contenue du node;
		if ((*lst)->cmd)
			g_free((*lst)->cmd);
		if ((*lst)->arg)
			ft_free_all((*lst)->arg);
		if ((*lst)->file_lst)
			ft_filelstclear(&(*lst)->file_lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_pipelst_printcmd(t_info_exec	**lst)
{
	t_info_exec	*temp;
	int			count;

	temp = *lst;
	count = 1;
	while(temp)
	{
		ft_putendl_fd("Commmand :", 1);
		if (temp->cmd)
			ft_putendl_fd(temp->cmd, 1);
		if (!temp->cmd)
			ft_putendl_fd("cmd NULL", 1);
		ft_putendl_fd("Arg :", 1);
		ft_print_tabstr(temp->arg);
		ft_print_filelst(&temp->file_lst);
		temp = temp->next;
		count++;
	}
}

void	ft_pipelst_reverse_printcmd(t_info_exec	**lst)
{
	t_info_exec	*temp;
	int			count;

	temp = *lst;
	temp = ft_pipelst_last(temp);
	count = 1;
	while(temp)
	{
		ft_putnbr_fd(count, 1);
		ft_putstr_fd(" .", 1);
		ft_putendl_fd(temp->cmd, 1);
		temp = temp->prev;
		count++;
	}
}


t_info_exec	*ft_make_pipelst(t_token ***array, t_state *state)
{
	size_t		i;
	t_info_exec	*lst;
	t_info_exec	*new;

	i = 0;
	lst = NULL;
	while(array[i])
	{
		new = ft_token_to_exec(array[i]);
		if (!new)
			return (garbage_destroy(), NULL);
		new->state = state;
		ft_pipelst_addback(&lst, new);
		i++;
	}
	return (lst);
}

size_t	ft_pipelst_size(t_info_exec *lst)
{
	t_info_exec	*temp;
	size_t		lst_size;

	temp = lst;
	lst_size = 0;
	while(temp)
	{
		temp->index = lst_size;
		lst_size++;
		temp = temp->next;
	}
	return(lst_size);
}
