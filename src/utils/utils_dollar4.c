#include "../../includes/minishell.h"

void	handle_escaped_chars(const char *value, int *i, size_t *len)
{
	if (value[*i] == '\\' && value[*i + 1])
	{
		*len += 2;
		*i += 2;
	}
	else
	{
		(*len)++;
		(*i)++;
	}
}
