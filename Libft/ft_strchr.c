#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 127)
	{
		while (s[i])
		{
			if ((unsigned char)s[i] == (unsigned char)c)
				return ((char *)&s[i]);
			i++;
		}
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
