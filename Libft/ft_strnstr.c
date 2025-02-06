#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	second_len;
	size_t	i;
	size_t	j;

	second_len = ft_strlen(little);
	if (second_len == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j] != '\0')
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
