#include "../../includes/minishell.h"

void	sigpipe_handler(int signo)
{
	t_data	*data;

	data = get_data();
	if (signo == SIGPIPE)
	{
		if (data->tmp_env)
			ft_free_multi_array(data->tmp_env);
		destroy_child_process(SUCCESS, NULL);
	}
}
