/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:18:29 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/18 15:39:38 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long long	get_atoi_num(char *str, int idx, long long num)
{
	long long	temp;

	temp = 0;
	if (str[idx] >= '0' && str[idx] <= '9')
		temp = num * 10 + (str[idx] - '0');
	else
		error_msg();
	return (temp);
}

int	check_atoi(char *str)
{
	long long	num;
	int			idx;
	int			sign;

	num = 0;
	idx = 0;
	sign = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
		if (str[idx] == '\0')
			error_msg();
	}
	while (str[idx])
	{
		num = get_atoi_num(str, idx, num);
		idx++;
	}
	return (num * sign);
}

void	check_num(int num, char *input)
{
	size_t	len;
	size_t	cnt;

	cnt = 0;
	if (!input)
		error_msg();
	len = ft_strlen(input);
	if (num < 0)
		cnt++;
	else if (num == 0 && len == 1)
		return ;
	while (num)
	{
		cnt++;
		num /= 10;
	}
	if (cnt != len)
		error_msg();
}
