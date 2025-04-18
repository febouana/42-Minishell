#include "../../includes/minishell.h"

t_token	*last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void	remove_quotes(t_data *data)
{
	t_token	*token;
	char	*new_value;

	token = data->token;
	while (token)
	{
		new_value = return_new_value(token->value, false, false);
		free(token->value);
		token->value = new_value;
		token = token->next;
	}
}

char	*return_new_value(char *value, bool squote_open, bool dquote_open)
{
	int		i;
	int		j;
	char	*new_value;

	i = 0;
	j = 0;
	new_value = malloc(ft_strlen(value) + 1);
	if (!new_value)
		return (NULL);
	while (value[i])
	{
		if (value[i] == '\'' && !dquote_open)
			squote_open = !squote_open;
		else if (value[i] == '"' && !squote_open)
			dquote_open = !dquote_open;
		else
			new_value[j++] = value[i];
		i++;
	}
	new_value[j] = '\0';
	return (new_value);
}

void	printf_tokens(t_data *data)
{
	t_token	*token;

	token = data->token;
	while (token)
	{
		printf("Token [value: %s | type: %d (", token->value, token->type);
		if (token->type == 1)
			printf("INPUT)]\n");
		else if (token->type == 2)
			printf("HEREDOC)]\n");
		else if (token->type == 3)
			printf("TRUNC)]\n");
		else if (token->type == 4)
			printf("APPEND)]\n");
		else if (token->type == 5)
			printf("PIPE)]\n");
		else if (token->type == 6)
			printf("CMD)]\n");
		else if (token->type == 7)
			printf("ARG)]\n");
		token = token->next;
	}
}

void	remove_backslash(t_data *data)
{
	t_token	*token;
	char	*new_value;
	int		i;
	int		j;

	token = data->token;
	while (token)
	{
		new_value = malloc(ft_strlen(token->value) + 1);
		if (!new_value)
			cleanup(ERROR, "Error: malloc failed\n", ERROR, 2);
		i = 0;
		j = 0;
		while (token->value[i])
		{
			if (token->value[i] != '\\')
				new_value[j++] = token->value[i];
			i++;
		}
		new_value[j] = '\0';
		free(token->value);
		token->value = new_value;
		token = token->next;
	}
}
