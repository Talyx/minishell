#include "minishell.h"

void	parse_env(t_minishell *mini, char **env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	mini->env = malloc(sizeof(t_list *));
	tmp = NULL;
	ft_lstadd_back(&tmp, ft_lstnew(ft_strdup("")));
	while (env[i])
	{
		ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(env[i])));
		i++;
	}
	*mini->env = tmp;
}

int	print_env(t_list **env)
{
	t_list	*tmp;
	char	*envp;

	tmp = *env;
	while (tmp)
	{
		envp = tmp->content;
		if (envp && ft_strlen(envp) > 0)
		{
			ft_putstr(envp);
			ft_putstr("\n");
		}
		tmp = tmp->next;
	}
	return (0);
}
