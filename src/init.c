/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:33:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 21:11:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	init_cub3d(t_env *env)
{
	int	fd;

	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (puterr("Error\nUnable to open map: ", env->map.path));
	env->map.width = 0;
	env->map.height = 0;
	env->map.ceiling_color = 0;
	env->map.floor_color = 0;
	env->player.pos.x = 0;
	env->player.pos.y = 0;
	if (parse_information(env))
		return (1);
	if (get_map_information(env))
		return (1);
	env->mapc = ft_calloc((env->map.width * env->map.height), sizeof(char));
	if (!env->mapc)
		return (puterr("Error\nMemory allocation error \
						during map initialization\n", NULL));
	if (fill_map(env))
		return (1);
	if (check_map(env))
		return (1);
	if (convert_colors(env))
		return (1);
	return (0);
}

int	get_map_information(t_env *env)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(env->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line && (!ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "NO", 2) || \
					!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) || \
					!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1) || \
					!ft_strncmp(line, "\n", 1)))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		if (check_line(line, &fd, env))
			return (1);
		free(line);
		env->map.height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	set_start(t_v2 v, t_env *env)
{
	if (env->player.pos.x != 0 || env->player.pos.y != 0)
		return (puterr("Error\nMultiple start position found on map.", NULL));
	env->player.pos.x = v.x * SIZE;
	env->player.pos.y = v.y * SIZE;
	env->player.s_dir = env->mapc[v.x + v.y * env->map.width];
	env->player.c_dir = env->mapc[v.x + v.y * env->map.width];
	env->mapc[v.x + v.y * env->map.width] = '0';
	return (0);
}
