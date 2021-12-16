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

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("text1.txt", O_RDONLY);
	
	s = get_next_line(fd);
	while (s != NULL)
	{
		printf("%s\n", s);
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	system("leaks a.out > .leaks_log.txt");
	return (0);
}
