#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*str;

	str = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		*str = 0;
		a++;
		str++;
	}
}
