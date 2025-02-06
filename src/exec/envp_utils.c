#include "../../includes/minishell.h"

int	cmd_list_len(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	if (!cmd)
		return (FAILURE);
	tmp = cmd;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	add_cmd_to_list(t_cmd *cmd, t_cmd *data_cmd)
{
	t_cmd	*last;

	last = return_last_cmd_node(data_cmd);
	if (!last)
		return (cleanup(ERROR, "Error: last node inaccessible\n", ERROR, 2));
	last->next = cmd;
	cmd->prev = last;
	return (SUCCESS);
}

t_cmd	*return_last_cmd_node(t_cmd *command)
{
	if (!command)
		return (NULL);
	while (command->next)
		command = command->next;
	return (command);
}
