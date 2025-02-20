/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:59:46 by moel-oua          #+#    #+#             */
/*   Updated: 2025/02/20 09:44:35 by moel-oua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h> 
# include <stdlib.h>

int		ft_atoi_bonus(char *str);
void	received_bonus(int sig, siginfo_t *info, void *context);
void	print_string_bonus(char *str);
char	*itoi_bonus(int number);
void	terminate_bonus(int sig, siginfo_t *info, void *context);

#endif