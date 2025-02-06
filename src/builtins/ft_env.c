#include "../../includes/minishell.h"

int	ft_env(void)
{
	t_data	*data;
	t_env	*tmp;

	data = get_data();
	tmp = data->envp;
	if (!tmp)
		return (SUCCESS);
	while (tmp)
	{
		if (ft_strchr(tmp->line, '='))
			printf("%s\n", tmp->line);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (SUCCESS);
}
