#include "../../includes/minishell.h"

void	initialize_data(t_data **data)
{
	*data = get_data();
	(*data)->tmp_env = NULL;
	(*data)->token = NULL;
	(*data)->envp = NULL;
	(*data)->cmd = NULL;
	(*data)->line = NULL;
	(*data)->exit_status = 0;
	(*data)->current_pid = 0;
}

void	*get_data(void)
{
	static t_data	data;

	return (&data);
}
