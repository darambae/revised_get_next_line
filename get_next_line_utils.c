/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:55 by dabae             #+#    #+#             */
/*   Updated: 2023/11/23 14:22:48 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*ft_lastnode(t_list *buf_list)
{
	t_list *current;

	current = buf_list;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	prep_line(char **line, t_list *buf_list)
{
	int	i;
	int	j;

	j = 0;
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && buf_list->str_tmp[i] != '\n')
		{
			i++;
			j++;
		}
		if (buf_list->str_tmp[i] == '\n')
			j++;
		buf_list = buf_list->next;
	}
	*line = malloc(sizeof(char) * (j + 1));
}

void	free_list(t_list *buf_list)
{
	t_list	*tmp;
	t_list	*current;

	current = buf_list; 
	while (current)
	{
		free(current->str_tmp);
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	found_n(t_list *buf_list)
{
	int	i;
	t_list *last;

	last = ft_lastnode(buf_list);
	i = 0;
	while (last->str_tmp[i])
	{
		if (last->str_tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
