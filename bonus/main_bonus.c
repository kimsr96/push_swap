/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:16 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/19 08:08:24 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker_bonus.h"

static int	cnt_word(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	**save_word(char **save, char **split)
{
	int		i;
	int		j;
	int		cnt;
	char	**ret;

	i = cnt_word(save);
	j = cnt_word(split);
	if (j == 0)
		error_msg();
	cnt = 0;
	ret = (char **)malloc(sizeof(char *) * (i + j + 1));
	if (!ret)
		exit(1);
	ret[i + j] = NULL;
	while (cnt < i + j)
	{
		if (cnt < i)
			ret[cnt] = ft_strdup(save[cnt]);
		else
			ret[cnt] = ft_strdup(split[cnt - i]);
		cnt++;
	}
	save = free_arr(save);
	split = free_arr(split);
	return (ret);
}

static char	**make_str(int argc, char **argv)
{
	int		idx;
	char	**ret;
	char	**split;

	idx = 0;
	ret = NULL;
	while (++idx < argc)
	{
		split = ft_split(argv[idx], ' ');
		if (split == NULL || *split == NULL)
			error_msg();
		if (!ret)
			ret = split;
		else
			ret = save_word(ret, split);
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		idx;
	char	**s;

	if (argc < 2)
		return (0);
	idx = 0;
	s = make_str(argc, argv);
	init_stack(&ps, s);
	check_cmd(&ps);
	free_arr(s);
	return (0);
}
