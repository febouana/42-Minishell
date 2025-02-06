#include "libft.h"

static int	len_nbr(long n)
{
	int	compteur;

	compteur = 1;
	if (n < 0)
	{
		compteur++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		compteur++;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	i = len_nbr(nbr);
	str = (char *)malloc(len_nbr(nbr) + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	nbr = n;
	str[len_nbr(nbr)] = 0;
	return (str);
}
