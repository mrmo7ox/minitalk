/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:23:01 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/20 09:45:38 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(char *str)
{
	int			total;
	int			sign;
	long long	max;

	sign = 1;
	total = 0;
	max = 0;
	while (*str == '\t' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		max = (max * 10) + (*str - '0');
		total = max;
		if (total != max)
			(print_string("[KO] PID OVERFLOWED :("), exit(1));
		str++;
	}
	return (sign * max);
}

static int	get_len(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number)
	{
		i++;
		number /= 10;
	}
	return (i);
}

char	*itoi(int number)
{
	char	*res;
	int		len;

	len = get_len(number);
	res = malloc(len + 1);
	if (!res)
		return (res);
	res[len] = '\0';
	if (number == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (number < 0)
	{
		number = -number;
		res[0] = '-';
	}
	while (len)
	{
		len--;
		res[len] = (number % 10) + '0';
		number /= 10;
	}
	return (res);
}

void	print_string(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	terminate(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	write(1, "\nTerminating...\n", 15);
	exit(0);
}
