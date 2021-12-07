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
#include <stdio.h>
#include <fcntl.h>

char	*set_temp_line(char *buff, char *one_line)
{
	 
}

char	*read_file(int fd, char *buff, char *one_line)
{
	int	bytes;
	static char		*temp_line = NULL;
	
	ft_bzero(buff, BUFFER_SIZE + 1);
	bytes = -1;
	while (bytes != 0 && !find_endline(buff))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
		set_temp_line(buff, oneline, temp_line);
		ft_bzero(buff, BUFFER_SIZE);
	}
	if (bytes == 0)
		// while '\n' can be found in temp_str
		// cut the word from temp_str and return this.
	else // if find endline in buff
		// join the characters(include '\n') with temp_str and return the new str.
	return (one_line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*one_line;

	if (fd == -1)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	one_line = read_file(fd, buff, one_line); // get the return value
	return (one_line);
}


// TODO
// if the file is empty, stop with first read()
// if BUFFER_SIZE is 0
// if BUFFER_SIZE is too big