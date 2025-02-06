#include "../../includes/minishell.h"

bool	check_n_flag(char **cmd_param, int *i)
{
	int		j;
	bool	newline;

	newline = true;
	while (cmd_param[*i] && ft_strncmp(cmd_param[*i], "-n", 2) == 0)
	{
		j = 1;
		while (cmd_param[*i][j] == 'n')
			j++;
		if (!cmd_param[*i][j])
		{
			newline = false;
			(*i)++;
		}
		else
			break ;
	}
	return (newline);
}

int	ft_echo(char **cmd_param)
{
	int		i;
	bool	newline;

	i = 1;
	if (!cmd_param[i])
	{
		write(STDOUT_FILENO, "\n", 1);
		return (SUCCESS);
	}
	newline = check_n_flag(cmd_param, &i);
	while (cmd_param[i])
	{
		write(STDOUT_FILENO, cmd_param[i], ft_strlen(cmd_param[i]));
		if (cmd_param[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (newline)
		write(STDOUT_FILENO, "\n", 1);
	return (SUCCESS);
}
