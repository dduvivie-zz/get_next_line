#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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


char    *test(void)
{
    static char *s = NULL;
    char    *s2;

    if (!s)
    {
        s = ft_strdup("Hello!");
    }
    else
    {
        s2 = s;
        s = ft_strjoin(s, "Bye!");
        free(s2);
    }
    return (s);
}

int main(void)
{
    printf("%s\n", test());
    printf("%s\n", test());
    system("leaks test >> .leaks_log2.txt");
    return(0);
}