#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (c > 127)
	{
		while (s[a])
		{
			if (s[a] == (char)c)
				return ((char *)&s[a]);
			a++;
		}
		return (NULL);
	}
	while (s[a])
		a++;
	while (a >= 0)
	{
		if (s[a] == c)
			return ((char *)&s[a]);
		a--;
	}
	return (NULL);
}
