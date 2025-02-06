#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;

	str = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		*str = (unsigned char)c;
		a++;
		str++;
	}
	return (s);
}
