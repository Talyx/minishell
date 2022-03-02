#include "minishell.h"

int	read_line(t_minishell *mini)
{
	const char	*prompt;

	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, sig_handler);
	g_all_fd.not_line = 1;
	if (!(mini->exit_status))
		prompt = PROMPT_OK;
	else
		prompt = PROMPT_BAD;
	mini->line = readline(prompt);
	if (!mini->line)
	{
		free(mini->line);
		ft_putstr_fd("exit\n", 2);
		exit(mini->exit_status);
	}
	else if (ft_strlen(mini->line) == 0)
		return (0);
	else if (ft_strlen(mini->line) > 0)
		add_history(mini->line);
	g_all_fd.not_line = 0;
	return (1);
}
