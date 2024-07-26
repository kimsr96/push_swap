/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:06 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/19 13:45:21 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

void	*free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	is_sorted(t_stack *head)
{
	int		idx;
	t_stack	*curr;

	if (!head)
		return (0);
	idx = head->idx;
	curr = head->next;
	while (curr != head)
	{
		if (idx > curr->idx)
			return (0);
		idx = curr->idx;
		curr = curr->next;
	}
	return (1);
}
