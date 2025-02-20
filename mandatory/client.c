/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:47:49 by mrmo7ox           #+#    #+#             */
/*   Updated: 2025/02/19 22:21:29 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	sender(char character, int pid)
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

int	is_valid(char *dc)
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
	pid = ft_atoi(av[1]);
	str = av[2];
	while (*str)
	{
		sender(*str, pid);
		str++;
	}
	return (0);
}
