/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:55 by dabae             #+#    #+#             */
/*   Updated: 2023/11/21 17:37:33 by dabae            ###   ########.fr       */
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
void	free_list(t_list **buf_list)
{
	t_list	*tmp;
	t_list	*current;

	current = *buf_list; 
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

	if (!buf_list)
		return (0);
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
		{
			if (buf_list->str_tmp[i] == '\n')
				return (1);
			i++;
		}
		buf_list = buf_list->next;
	}
	return (0);
}
