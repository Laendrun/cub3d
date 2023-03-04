/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:22:47 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:28:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_udr(t_v2 v, t_env *env)
{
	return (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x + 1) + v.y * env->map.width)] == ' ');
}

static int	check_udl(t_v2 v, t_env *env)
{
	return (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x - 1) + v.y * env->map.width)] == ' ');
}

static int	check_udlr(t_v2 v, t_env *env)
{
	return (env->mapc[(int)(v.x + (v.y - 1) * env->map.width)] == ' ' || \
			env->mapc[(int)(v.x + (v.y + 1) * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x - 1) + v.y * env->map.width)] == ' ' || \
			env->mapc[(int)((v.x + 1) + v.y * env->map.width)] == ' ');
}

int	line_nok(char *line, t_env *env)
{
	while (*line)
	{
		if (!(*line == '0' || *line == '1' || *line == 'N' || \
			*line == 'S' || *line == 'W' || *line == 'E' || *line == ' '))
			return (puterr("Error\n", \
					"Parsing: map contains unauthorized characters."));
		if (ft_strlen(line) >= env->map.width)
			env->map.width = ft_strlen(line);
		line++;
	}
	return (0);
}

int	space_around(t_v2 v, t_env *env)
{
	if (v.x == 0)
	{
		if (check_udr(v, env))
			return (1);
	}
	else if (v.x == env->map.width - 1)
	{
		if (check_udl(v, env))
			return (1);
	}
	else
	{
		if (check_udlr(v, env))
			return (1);
	}
	return (0);
}
