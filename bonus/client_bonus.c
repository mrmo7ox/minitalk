/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:47:49 by mrmo7ox           #+#    #+#             */
/*   Updated: 2025/02/20 09:44:46 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sender(char character, int pid)
{
	int	index;
	int	sig;

	index = 0;
	while (index < 8)
	{
		usleep(50);
		if (character & (1 << index))
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(pid, sig) == -1)
			exit(1);
		usleep(50);
		index++;
	}
}

static int	is_valid(char *dc)
{
	int	i;

	i = 0;
	while (dc[i] != '\0')
	{
		if (!(dc[i] >= '0' && dc[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	reciv_bonus(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)*info;
	if (sig == SIGUSR1)
	{
		print_string_bonus("[OK] message received");
	}
}

static void	h_seg_bonus(void)
{
	struct sigaction	sa;
	struct sigaction	sa_term;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = reciv_bonus;
	sigaction(SIGUSR1, &sa, NULL);
	sigemptyset(&sa_term.sa_mask);
	sa_term.sa_flags = SA_SIGINFO;
	sa_term.sa_sigaction = terminate_bonus;
	sigaction(SIGINT, &sa_term, NULL);
	sigaction(SIGTERM, &sa_term, NULL);
}

int	main(int ac, char **av)
{
	char	*str;
	int		pid;

	if (ac != 3)
	{
		write(2, "ERORR!", 6);
		return (1);
	}
	if (!is_valid(av[1]))
	{
		write(2, "ERORR1!", 6);
		return (1);
	}
	pid = ft_atoi_bonus(av[1]);
	str = av[2];
	h_seg_bonus();
	while (*str)
	{
		sender(*str, pid);
		str++;
	}
	sender('\0', pid);
	return (0);
}
