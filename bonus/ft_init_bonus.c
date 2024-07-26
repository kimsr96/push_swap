/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:05:02 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/18 15:38:06 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

t_stack	*new_node(int num, int idx)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	ft_memset(new, 0, sizeof(t_stack));
	new->num = num;
	new->idx = idx;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*add_node(t_stack **head, int num, int idx)
{
	t_stack	*new;

	new = new_node(num, idx);
	if (*head == NULL)
	{
		*head = new;
		new->next = *head;
		new->prev = *head;
	}
	else
	{
		(*head)->prev->next = new;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		new->next = *head;
	}
	return (new);
}

void	init_stack(t_ps *ps, char **argv)
{
	int		i;
	int		num;

	if (*argv == NULL)
		error_msg();
	i = 0;
	ps->a_top = NULL;
	ps->b_top = NULL;
	while (argv[i])
	{
		num = check_atoi(argv[i]);
		add_node(&(ps->a_top), num, 0);
		check_num(num, argv[i]);
		add_index_l(ps, num);
		i++;
	}
	ps->a_size = i;
	ps->b_size = 0;
	add_index_r(ps);
}
