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
	static char		*temp_line;

	if (!temp_line)
		// initialize temp string

	// 
}

char	*read_file(int fd, char *buff, char *one_line)
{
	int	rc;
	
	ft_bzero(buff, BUFFER_SIZE + 1);
	rc = -1;
	while (rc != 0 && !find_endline(buff))
	{
		rc = read(fd, buff, BUFFER_SIZE);
		buff[rc] = '\0';
		set_temp_line(buff, oneline);
		if (rc == 0)
		ft_bzero(buff, BUFFER_SIZE);
	}
	if (rc == 0)
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
	one_line = read_file(fd, buff, one_line);
	return (one_line);
}

int main(void)
{
	int	fd;
	char *s;
	int	finish;

	fd = open("text1.txt", O_RDONLY);
	finish = 0;
	while (!finish)
	{
		s = get_next_line(fd);
		if (s == NULL)
			finish = 1;
		printf("%s\n", s);
		free(s);
	}
	close(fd);
	return (0);
}