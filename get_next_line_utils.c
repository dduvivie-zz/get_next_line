/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:37:54 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 17:37:56 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = '\0';
		str++;
	}
}

/*
This function checks if there is a '\n' in the string which was read by read(), 
and if so, get the length of string until the '\n'.
*/
int	find_endline(char *str)
{
	while (*str != '\0' && *str != '\n')
		str++;
	if (*str == '\0')
		return (0);
	return (1);
}

/*
Allocates sufficient memory for a copy of the string 's1',
does the copy, and returns a pointer to it.
*/
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
	{
		return (0);
	}
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
