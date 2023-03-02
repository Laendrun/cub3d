/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:38 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 18:56:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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

int	convert_colors(t_env *env)
{
	// check string format before converting
	// should be like 100,100,100
	char	**tmp;
	int		comp[3];

	tmp = ft_split(env->map.f_color, ',');
	comp[0] = ft_atoi(tmp[0]);
	comp[1] = ft_atoi(tmp[1]);
	comp[2] = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	env->map.floor_color = (comp[0] << 16) | (comp[1] << 8) | comp[2];
	tmp = ft_split(env->map.c_color, ',');
	comp[0] = ft_atoi(tmp[0]);
	comp[1] = ft_atoi(tmp[1]);
	comp[2] = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	env->map.ceiling_color = (comp[0] << 16) | (comp[1] << 8) | comp[2];
	return (0);
}
