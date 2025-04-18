#include "../../includes/minishell.h"

int	cleanup(int exit_status, char *message, int exit_call, int fd)
{
	t_data	*data;

	data = get_data();
	if (data)
	{
		free_data(&data);
		if (exit_status != NO_CHANGE)
			data->exit_status = exit_status;
	}
	if (message)
		ft_putstr_fd(message, fd);
	if (exit_call == NO_EXIT && fd != 1)
		return (exit_status);
	if (data)
	{
		if (data->envp)
			destroy_envp_list(&data->envp);
		if (data->line)
		{
			free(data->line);
			data->line = NULL;
		}
	}
	rl_clear_history();
	exit(exit_call);
}

void	free_data(t_data **data)
{
	if (!data || !(*data))
		return ;
	if ((*data)->token)
		free_tokens(data);
	if ((*data)->cmd)
		free_commands(data);
}

void	free_tokens(t_data **data)
{
	t_token	*current;
	t_token	*next;

	if (!data || !(*data) || !(*data)->token)
		return ;
	current = (*data)->token;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = NULL;
		current = next;
	}
	(*data)->token = NULL;
}

void	free_commands(t_data **data)
{
	t_cmd	*current;
	t_cmd	*next;
	int		i;

	if (!data || !*data || !(*data)->cmd)
		return ;
	current = (*data)->cmd;
	while (current)
	{
		next = current->next;
		if (current->cmd_param)
		{
			i = 0;
			if (current->cmd_param[i])
				free(current->cmd_param[i]);
			while (current->cmd_param[i] && ++i)
				free(current->cmd_param[i]);
			free(current->cmd_param);
			current->cmd_param = NULL;
		}
		free(current);
		current = NULL;
		current = next;
	}
	(*data)->cmd = NULL;
}
