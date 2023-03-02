/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:38 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 16:41:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*set_spaces(char *line, t_env *env)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(line);
	while (len < env->map.width)
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		len++;
	}
	return (line);
}

void	print_map(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			ft_printf("%c", env->mapc[x + y * env->map.width]);
			x++;
		}
		y++;
		ft_printf("\n");
	}
}
