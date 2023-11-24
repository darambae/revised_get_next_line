/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:24:06 by dabae             #+#    #+#             */
/*   Updated: 2023/11/24 09:44:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (buf_list && buf_list->next)
		buf_list = buf_list->next;
	return (buf_list);
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

	while (buf_list)
	{
		tmp = buf_list;
		buf_list = buf_list->next;
		free(tmp->str_tmp);
		free(tmp);
	}
}

int	found_n(t_list *buf_list)
{
	int		i;
	t_list	*last;

	if (!buf_list)
		return (0);
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

