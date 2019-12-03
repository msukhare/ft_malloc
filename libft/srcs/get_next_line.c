/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:20:35 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 11:53:16 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl		*ft_init_struct(void)
{
	t_gnl			*to_ret;

	if (!(to_ret = (t_gnl*)malloc(sizeof(t_gnl) * 1)))
		return (NULL);
	to_ret->index = 0;
	if (!(to_ret->p_line = (char*)ft_memalloc(1)))
	{
		free(to_ret);
		return (NULL);
	}
	return (to_ret);
}

static int			ft_read_file(int fd, t_gnl *file)
{
	char			buff[BUFF_SIZE_GNL + 1];
	char			*tmp;
	int				readed;

	while ((readed = read(fd, buff, BUFF_SIZE_GNL)) > 0)
	{
		buff[readed] = '\0';
		tmp = file->p_line;
		if (!(file->p_line = ft_strjoin(file->p_line, buff)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		if (ft_if_c_in_str(buff, '\n'))
			return (0);
	}
	return (0);
}

static int			ft_len(t_gnl *file)
{
	int				to_ret;
	int				i;

	to_ret = 0;
	i = file->index;
	while (file->p_line[i] && file->p_line[i] != '\n')
	{
		to_ret++;
		i++;
	}
	return (to_ret);
}

static int			ft_put_in_line(t_gnl *file, char **line)
{
	int				writed;

	writed = 0;
	if (!(line[0] = (char *)malloc(sizeof(char) * (ft_len(file) + 1))))
		return (-1);
	while (file->p_line[file->index] && file->p_line[file->index] != '\n')
	{
		line[0][writed] = file->p_line[file->index];
		writed++;
		file->index++;
	}
	line[0][writed] = '\0';
	if (file->p_line[file->index] == '\n')
	{
		file->index++;
		writed++;
	}
	return (writed);
}

int					get_next_line(int fd, char **line)
{
	static t_gnl	*file;
	int				writed;

	if (!line || BUFF_SIZE_GNL < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!file && !(file = ft_init_struct()))
		return (-1);
	if (ft_read_file(fd, file) < 0)
	{
		free(file->p_line);
		free(file);
		return (-1);
	}
	if ((writed = ft_put_in_line(file, line)) < 0)
	{
		free(file->p_line);
		free(file);
		return (-1);
	}
	if (writed == 0)
	{
		free(file->p_line);
		free(file);
	}
	return (writed);
}
