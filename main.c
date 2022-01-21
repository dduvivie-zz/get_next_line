/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:37:36 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 17:37:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_gnl(char *s)
{
	if (s == NULL)
		printf("NULL\n");
	else
		printf("%s\n", s);
}

/*
**	gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
*/

int	main()
{
	int		fd;
	char	*s;
		
	fd = open("gnlTester/files/nl", O_RDONLY);
	
	s = get_next_line(fd);
	if (s == NULL)
		printf("NULL\n");
	while (s != NULL)
	{
		print_gnl(s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	system("leaks a.out > .leaks_log.txt");
	
	return (0);
}
