#include "../../includes/minishell.h"

bool	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
		return (print_error("Error: getcwd\n"), 1);
}
