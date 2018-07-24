/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:47:26 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/17 14:37:51 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	append_file(char **f_content, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while (!contains(*f_content, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*f_content = ft_concat(*f_content, buf);
	}
	return (ret);
}

static char	*get_first_line(char **str)
{
	int		i;
	char	*line;
	int		line_len;
	char	*temp_str;

	temp_str = *str;
	line_len = 0;
	while (temp_str[line_len] != '\n' && temp_str[line_len])
		line_len++;
	if (!(line = (char *)malloc(sizeof(char) * (line_len + 1))))
		return (NULL);
	i = 0;
	while (temp_str[i] && temp_str[i] != '\n')
	{
		line[i] = temp_str[i];
		i++;
	}
	line[i] = '\0';
	if (temp_str[i] == '\n')
		i++;
	*str = ft_strdup(&(temp_str[i]));
	free(temp_str);
	return (line);
}

t_file		*get_file(t_list **files, int fd)
{
	t_list	*temp;
	t_list	*new_elem;

	temp = *files;
	while (temp)
	{
		if (((t_file *)temp->content)->fd == fd)
			return ((t_file *)temp->content);
		temp = temp->next;
	}
	new_elem = ft_lstnew(NULL, 0);
	if (!(new_elem->content = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	((t_file *)new_elem->content)->file_content = NULL;
	((t_file *)new_elem->content)->fd = fd;
	ft_lstadd(files, new_elem);
	return ((t_file *)(new_elem->content));
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*files = NULL;
	t_file			*file;

	if (fd < 0 || line == NULL)
		return (-1);
	file = get_file(&files, fd);
	if (!contains(file->file_content, '\n'))
	{
		if (append_file(&(file->file_content), fd) == -1)
		{
			ft_lstdelone(&files, file);
			return (-1);
		}
		if (file->file_content == NULL || *(file->file_content) == '\0')
		{
			free(file->file_content);
			ft_lstdelone(&files, file);
			return (0);
		}
	}
	*line = get_first_line(&(file->file_content));
	return (1);
}
