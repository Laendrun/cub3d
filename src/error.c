/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:53:03 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 21:13:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	puterr(char *s1, char *s2)
{
	while (s1 && *s1)
		write(2, s1++, 1);
	while (s2 && *s2)
		write(2, s2++, 1);
	write(2, "\n", 1);
	return (1);
}

int	line_nok(char *line, t_env *env)
{
	while (*line)
	{
		if (!(*line == '0' || *line == '1' || *line == 'N' || \
			*line == 'S' || *line == 'W' || *line == 'E' || *line == ' '))
			return (puterr("Error\nParsing: map contains unauthorized characters.", 0));
		if (ft_strlen(line) >= env->map.width)
			env->map.width = ft_strlen(line);
		line++;
	}
	return (0);
}

int	check_map(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (x < env->map.width)
	{
		if (env->mapc[x + y * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	x = 0;
	while (x < env->map.width)
	{
		if (env->mapc[x + (env->map.height - 1) * env->map.width] == '0')
			return (puterr("Error\nMap not enclosed in walls.", NULL));
		x++;
	}
	y = 1;
	while (y < env->map.height - 1)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '0')
				if (space_around((t_v2){x, y}, env))
					return (puterr("Error\nMap not enclosed in walls.", NULL));
			if (is_dir(env->mapc[x + y * env->map.width]))
				if (set_start((t_v2){x, y}, env))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	space_around(t_v2 v, t_env *env)
{
	if (v.x == 0)
	{
		// UP DOWN RIGHT
		if (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x + 1) + v.y * env->map.width)] == ' ')
			return (1);
	}
	else if (v.x == env->map.width - 1)
	{
		// UP DOWN LEFT
		if (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x - 1) + v.y * env->map.width)] == ' ')
			return (1);
	}
	else
	{
		// UP DOWN LEFT RIGHT
		if (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x - 1) + v.y * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x + 1) + v.y * env->map.width)] == ' ')
			return (1);
	}
	return (0);
}
