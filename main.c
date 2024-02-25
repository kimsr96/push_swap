/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:00:05 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/25 14:19:05 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		init_stack(&ps, ft_split(argv[1], ' '));
	else
		init_stack(&ps, &argv[1]);
	//if (!is_sorted(ps.a_top))
	sort_stack(&ps);
	return (0);
}