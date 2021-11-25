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

char	*get_line()

char	*get_next_line(int fd)
{
	char	*buff;
	char	c;
	int		i;
	int		rc;

	if (fd == -1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	c = ' ';
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		buff[i] = c;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int main(void)
{
	int	fd;
	char *s;
    char *s2;

	fd = open("text1.txt", O_RDONLY);

	s = get_next_line(fd);
	printf("%s\n", s);
    s2 = get_next_line(fd);
	printf("%s\n", s2);
	close(fd);
	return (0);
}