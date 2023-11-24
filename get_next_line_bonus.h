/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:23:51 by dabae             #+#    #+#             */
/*   Updated: 2023/11/24 09:43:25 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_tmp;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);

int		found_n(t_list *buf_list);

int		ft_strlen(char *s);

void	free_list(t_list *buf_list);

void	prep_line(char **line, t_list *buf_list);

t_list	*ft_lastnode(t_list *buf_list);
#endif

