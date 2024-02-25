/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:05:02 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 14:20:01 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	ft_memset(new, 0, sizeof(t_stack));
	new->num = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack *add_node(t_stack **head, int data)
{
	t_stack	*new;

	new = new_node(data);
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

void	free_node(t_stack **head)
{
	t_stack	*curr;
	t_stack	*next;

	if (*head == NULL)
		return ;
	curr = *head;
	while (curr->next != *head)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(curr);
	*head = NULL;
}

void	init_stack(t_ps *ps, char **argv)
{
	int		i;

	i = 0;
	ps->a_top = NULL;
	ps->b_top = NULL;
	while (argv[i])
    {
		add_node(&(ps->a_top), ft_atoi(argv[i]));
        i++;
    }
    ps->a_size = i;
    ps->b_size = 0;
	//if (i <= 3 && !is_sorted(ps->a_top))
	//	sort_small_stack(ps, i, 'a');
	//print_stack(ps->a_top, 'a');
	//print_stack(ps->b_top, 'b');
}
