/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:48:01 by mrmo7ox           #+#    #+#             */
/*   Updated: 2025/02/20 09:44:13 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_back(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
	{
		(print_string_bonus("[KO] KILL CANT SEND"), exit(1));
	}
}

void	received_bonus(int sig, siginfo_t *info, void *context)
{
	static char	res;
	static int	index;
	static int	pid;

	(void)info;
	(void)context;
	if (pid != info->si_pid)
	{
		res = 0;
		index = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		res |= (1 << index);
	index++;
	if (index == 8)
	{
		write(1, &res, 1);
		if (res == '\0')
			handle_back(info->si_pid);
		res = 0;
		index = 0;
	}
}

void	setup_signals_bonus(void)
{
	struct sigaction	sa;
	struct sigaction	sa_term;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = received_bonus;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigemptyset(&sa_term.sa_mask);
	sa_term.sa_flags = SA_SIGINFO;
	sa_term.sa_sigaction = terminate_bonus;
	sigaction(SIGINT, &sa_term, NULL);
	sigaction(SIGTERM, &sa_term, NULL);
}

int	main(int ac, char **dc)
{
	pid_t	pid;
	char	*pid_str;

	(void)dc;
	if (ac != 1)
	{
		print_string_bonus("[KO] RUN THE ./server WITH NO ARGS");
		return (1);
	}
	pid = getpid();
	pid_str = itoi_bonus(pid);
	print_string_bonus(pid_str);
	free(pid_str);
	setup_signals_bonus();
	while (1)
		pause();
	return (0);
}
