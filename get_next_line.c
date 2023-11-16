/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:07:09 by dabae             #+#    #+#             */
/*   Updated: 2023/11/15 16:07:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static	char	*copy_rest(t_list *last_node)
{
	int		i;
	int		rest_len;
	char	*rest;

	i = 0;
	while (last_node->str_tmp[i] && last_node->str_tmp[i] != '\n')
		i++;
	rest_len = 0;
	if (last_node->str_tmp[i] == '\n')
	{
		while (last_node->str_tmp[i + 1 + rest_len]
			&& (i + 1 + rest_len) < BUFFER_SIZE)
			rest_len++;
	}
	rest = (char *)malloc(sizeof(char) * (rest_len + 1));
	if (rest)
	{
		rest[rest_len] = '\0';
		while (--rest_len >= 0)
			rest[rest_len] = last_node->str_tmp[i + 1 + rest_len];
	}
	else
		rest = NULL;
	return (rest);
}

static	void	extract_rest(t_list **buf_list)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*rest;

	while ((*buf_list)->next)
		(*buf_list) = (*buf_list)->next;
	last_node = *buf_list;
	rest = copy_rest(last_node);
	free_list(buf_list);
	if (rest)
	{
		new_node = malloc(sizeof(t_list));
		if (new_node)
		{
			new_node->str_tmp = rest;
			new_node->next = NULL;
			*buf_list = new_node;
		}
		else
		{
			free(rest);
			*buf_list = NULL;
		}
	}
}

static	void	retrieve_line(t_list *buf_list, char **line)
{
	int	i;
	int	j;

	*line = (char *)malloc(sizeof(char) * (line_len(buf_list) + 1));
	if (!*line || !buf_list)
		return ;
	j = 0;
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i])
		{
			if (buf_list->str_tmp[i] == '\n')
			{
				(*line)[j++] = '\n';
				(*line)[j] = '\0';
				return ;
			}
			(*line)[j++] = buf_list->str_tmp[i++];
		}
		buf_list = buf_list->next;
	}
	(*line)[j] = '\0';
}

static	void	create_list(t_list **buf_list, int fd)
{
	char	*buffer;
	int		bytes_read;

	while (!found_n(*buf_list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
		{
			free_list(buf_list);
			return ;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			free_list(buf_list);
			return ;
		}
		buffer[bytes_read] = '\0';
		add_node(buf_list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*buf_list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	create_list(&buf_list, fd);
	if (!buf_list)
		return (NULL);
	retrieve_line(buf_list, &line);
	extract_rest(&buf_list);
	return (line);
}
