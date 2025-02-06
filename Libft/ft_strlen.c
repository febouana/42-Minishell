#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a])
		a++;
	return (a);
}
