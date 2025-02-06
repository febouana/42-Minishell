#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (len <= 0 || start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!(str))
		return (NULL);
	ft_memcpy(str, &s[start], len);
	str[len] = 0;
	return (str);
}
