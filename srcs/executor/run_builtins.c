#include "minishell.h"

int	is_builtins(t_command *command)
{
	if (ft_strequ(command->path, "env"))
		return (1);
	else if (ft_strequ(command->path, "pwd"))
		return (1);
	else if (ft_strequ(command->path, "echo"))
		return (1);
	else if (ft_strequ(command->path, "export"))
		return (1);
	else if (ft_strequ(command->path, "unset"))
		return (1);
	else if (ft_strequ(command->path, "cd"))
		return (1);
	else if (ft_strequ(command->path, "exit"))
		return (1);
	return (0);
}

int	run_builtins(t_minishell *mini, t_command *command)
{
	if (ft_strequ(command->path, "env"))
		return (print_env(mini->env));
	else if (ft_strequ(command->path, "pwd"))
		return (run_pwd());
	else if (ft_strequ(command->path, "echo"))
		return (run_echo(command));
	else if (ft_strequ(command->path, "export"))
		return (run_export(command, mini->env));
	else if (ft_strequ(command->path, "unset"))
		return (run_unset(command, mini->env));
	else if (ft_strequ(command->path, "cd"))
		return (run_cd(command, mini->env));
	else if (ft_strequ(command->path, "exit"))
		return (run_exit(mini, command));
	return (1);
}
