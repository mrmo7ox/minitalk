/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:59:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/19 22:21:11 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	sender(char character, int pid);
int		ft_atoi(char *str);
void	received(int sig, siginfo_t *info, void *context);
void	print_string(char *str);
char	*itoi(int number);
void	terminate(int sig, siginfo_t *info, void *context);

#endif