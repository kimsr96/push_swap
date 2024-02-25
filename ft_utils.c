/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:06 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 14:12:12 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_stack *head)
{
	int		num;
	t_stack	*curr;

    if (!head)
        return (0);
	num = head->num;
	curr = head->next;
	while (curr != head)
	{
		if (num > curr->num)
			return (0);
		num = curr->num;
		curr = curr->next;
	}
	return (1);
}

void    print_stack(t_stack *head, char c)
{
	t_stack *curr;

	curr = head;
	if (!head)
	{
		printf("no stack\n");
		return ;
	}
	printf("%c stack\n", c);
	while (curr->next != head)
	{
		printf("%d\n", curr->num);
		curr = curr->next;
	}
	printf("%d\n", curr->num);
    printf("address: %p\n", head);
}