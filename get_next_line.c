/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:37:36 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 17:37:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reset_temp_line(char *temp_line)
{
	int		char_cut;
	char	*tmp;

	char_cut = ft_strlen(temp_line, 1);
	tmp = ft_strdup(temp_line + char_cut);
	if (!tmp)
		return(NULL);
	free(temp_line);
	return (tmp);
}

char	*set_temp_line(char *buff, char *temp_line)
{
	char	*cpy_temp_line;

	if (temp_line == NULL)
	{
		temp_line = ft_strdup(buff);
		if (!temp_line)
			return (NULL);
	}
	else
	{
		cpy_temp_line = ft_strdup(temp_line);
		free(temp_line);
		temp_line = NULL;
		temp_line = ft_strjoin(cpy_temp_line, buff);
		free(cpy_temp_line);
		cpy_temp_line = NULL;
	}
	return (temp_line);
}

char	*get_one_line(char *temp_line, char *one_line)
{
	int	len;
	int	i;

	len = ft_strlen(temp_line, 1);
	i = 0;
	one_line = malloc((len + 1) * sizeof(char));
	if (!one_line)
	{
		free(temp_line);
		temp_line = NULL;
		return (NULL);
	}
	while (*temp_line != '\n')
	{
		one_line[i] = *temp_line;
		temp_line++;
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

char	*read_file(int fd, char *buff, char *one_line, char **temp_line)
{
	int		bytes;

	bytes = -1;
	while (bytes != 0 && !find_endline(buff))
	{
		ft_bzero(buff, BUFFER_SIZE);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		buff[bytes] = '\0';
		*temp_line = set_temp_line(buff, *temp_line);
		if (!*temp_line)
			return (NULL);
	}
	if (*temp_line == NULL || ft_strlen(*temp_line, 0) == 0)
		return (NULL);
	else if (!find_endline(*temp_line))
	{
		free(one_line);
		return (*temp_line);
	}
	one_line = get_one_line(*temp_line, one_line);
	*temp_line = reset_temp_line(*temp_line);
	if (!*temp_line)
		return (NULL);
	return (one_line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*one_line;
	static char		*static_line = NULL;

	if (fd > -1 || BUFFER_SIZE == 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	one_line = NULL;
	one_line = read_file(fd, buff, one_line, &static_line);
	free(buff);
	return (one_line);
}

/*
// TODO
// if the file is empty, stop with first read()
// if BUFFER_SIZE is too big (use OPEN_MAX)
*/