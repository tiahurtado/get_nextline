#include "get_next_line.h"

char *ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;
	size_t c;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c])
	{
		str[i + c] = s2[c];
		c++;
	}
	str[i + c] = '\0';
	return (str);
}

int ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
