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

char	*get_next_line(int fd)
{
	char	*buff;
	int		rc;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	rc = read(fd, buff, BUFFER_SIZE);
	if (rc == -1)
	{
		printf("file read error\n");
		return (NULL);
	}
	else
	{
		buff[rc] = '\0';
		return (buff);
	}

}

int main(void)
{
	int	fd;
	char *s;

	fd = open("text1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file open error\n");
		return(0);
	}
	s = get_next_line(fd);
	printf("%s\n", s);
	close(fd);
	return (0);
}