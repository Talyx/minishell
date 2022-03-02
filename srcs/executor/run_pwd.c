#include "minishell.h"

int	run_pwd(void)
{
	char	arr[4096];

	if (getcwd(arr, 4096))
	{
		ft_putstr(arr);
		ft_putstr("\n");
		return (0);
	}
	else
		return (1);
}

char	*get_pwd(void)
{
	char	arr[4096];

	if (getcwd(arr, 4096))
		return (ft_strdup(arr));
	else
		return (NULL);
}

int	update_pwd(t_list **env)
{
	char	*pwd;
	char	*new_pwd;

	pwd = get_pwd();
	if (!pwd)
		return (1);
	new_pwd = ft_strjoin("PWD=", pwd);
	if (!new_pwd)
		return (0);
	update_env(env, "PWD", new_pwd);
	free(pwd);
	free(new_pwd);
	return (0);
}
