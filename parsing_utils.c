/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:24:03 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/29 12:30:24 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arg(char **argv, int argc)
{
	char	*joined_arg;
	int		i;

	i = 1;
	joined_arg = NULL;
	if (argc == 2)
	{
		joined_arg = ft_strdup(argv[i]);
		return (joined_arg);
	}
	while (argv[i])
	{
		joined_arg = push_swap_strjoin(joined_arg, argv[i],
				ft_strlen(argv[i]) + ft_strlen(joined_arg));
		i++;
	}
	return (joined_arg);
}

char	*push_swap_strjoin(char *joined_arg, char *argv, int len)
{
	char	*new;
	int		i;
	int		j;
	int		len_joined;

	new = NULL;
	if (joined_arg == NULL)
	{
		return (ft_strdup(argv));
	}
	new = ft_calloc(sizeof(char *), len + 2);
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	len_joined = ft_strlen(argv);
	while (++i < len - len_joined)
	{
		new[i] = joined_arg[i];
	}
	new[i] = ' ';
	while (++i < len + 1)
		new[i] = argv[++j];
	free(joined_arg);
	return (new);
}
