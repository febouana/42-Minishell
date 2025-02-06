#include "../../includes/minishell.h"

int	cmd_list_envp(t_env *envp)
{
	t_env	*tmp;
	int		i;

	if (!envp)
		return (FAILURE);
	tmp = envp;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	search_and_del(char *var)
{
	int		len;
	t_env	*tmp;
	t_data	*data;

	data = get_data();
	len = ft_strlen(var);
	tmp = data->envp;
	while (tmp != NULL)
	{
		if (ft_strncmp(var, tmp->line, len) == 0)
		{
			del_node_envp(&(tmp));
			return (SUCCESS);
		}
		tmp = tmp->next;
	}
	return (ERROR);
}

int	unset_event_not_found(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (false);
		if (str[i] == '!')
			break ;
		i++;
	}
	if (i == ft_strlen(str))
		return (false);
	printf("minishell: !");
	while (str[i++])
		printf("%c", str[i]);
	printf(": event not found\n");
	return (true);
}

// "minishell: unset: %s not found\n" ==> pas present dans bash posix mais nul sans
int	ft_unset(char **cmd_param)
{
	if (cmd_param[1] && ft_strcmp(cmd_param[1], "") != 0)
	{
		if (unset_event_not_found(cmd_param[1]) == true)
			return (SUCCESS);
		if (cmd_param[1][0] == '-')
		{
			print_error("minishell: usage: unset [-f] [-v] [-n] [name ...]\n");
			return (2);
		}
		if (strcmp(cmd_param[1], "_") == 0)
			return (SUCCESS);
		if (search_and_del(cmd_param[1]) == SUCCESS)
			return (SUCCESS);
		else
			printf("minishell: unset: %s not found\n", cmd_param[1]);
	}
	return (SUCCESS);
}
