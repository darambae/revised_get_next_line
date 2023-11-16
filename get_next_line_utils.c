/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:55 by dabae             #+#    #+#             */
/*   Updated: 2023/11/15 16:13:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	add_node(t_list **buf_list, char *buffer)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->str_tmp = buffer;
		new->next = NULL;
		if (*buf_list == NULL)
			*buf_list = new;
		else
		{
			tmp = *buf_list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	else
		free(buffer);
}

void	free_list(t_list **buf_list)
{
	t_list	*tmp;

	if (!*buf_list)
		return ;
	while (*buf_list)
	{
		tmp = *buf_list;
		*buf_list = (*buf_list)->next;
		free(tmp->str_tmp);
		free(tmp);
	}
	*buf_list = NULL;
}

int	line_len(t_list *buf_list)
{
	int	i;
	int	j;

	j = 0;
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
		{
			if (buf_list->str_tmp[i] == '\n')
				return (++j);
			i++;
			j++;
		}
		buf_list = buf_list->next;
	}
	return (-1);
}

int	found_n(t_list *buf_list)
{
	int	i;

	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
		{
			if (buf_list->str_tmp[i] == '\n' && buf_list->str_tmp[i] == '\0')
				return (1);
			if (buf_list->str_tmp[i] == '\n')
				return (1);
			i++;
		}
		buf_list = buf_list->next;
	}
	return (0);
}
