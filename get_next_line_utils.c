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

#include "get_next_line.h"

/*
Writes 'n' zeroed bytes to the string 's'.
If 'n' is zero, bzero() does nothing.
*/
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
If the second parameter (flag) is 0, get the length of the string 's'.
If the second parameter (flag) is 1, get the length of one line, which means
that the counter stop at '\n' in 's'.

*/
size_t	ft_strlen(const char *s, int flag)
{
	size_t	len;

	len = 0;
	if (flag == 0)
	{
		while (*s != '\0')
		{
			len++;
			s++;
		}	
	}
	else
	{
		while (*s != '\n')
		{
			len++;
			s++;
		}
		len++;
	}
	return (len);
}

/*
This function allocates (with malloc) and returns a new string,
which is the result of the concatenation of ’s1’ and ’s2’.
Parameters: 1. The prefix string.
			2. The suffix string.
Return:		The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	i = 0;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
This function checks if there is a '\n' in the string 
which was given as parameter.
*/
int	find_endline(char *str)
{
	if (str == NULL)
		return (0);
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
	s2 = malloc((ft_strlen(s1, 0) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
