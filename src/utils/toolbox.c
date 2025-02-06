#include "../../includes/minishell.h"

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

bool	contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
