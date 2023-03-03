/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:33:00 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 14:06:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	fill_pt(t_env *env, t_v2 v, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			env->minimap.px[(v.x + i) + (v.y + j) * (env->map.width * SIZE)] = color;
			j++;
		}
		i++;
	}
}

int	init_minimap(t_env *env)
{
	size_t	x;
	size_t	y;
	// malloc a int array big enough to contain (width*SIZE)*(height*SIZE) pixels
	// fill the array with the corresponding pixels
	// (0;0) in the map file corresponds to pixels (0;0) to (SIZE;SIZE) in this minimap array
	// then at render time, loop over the whole array and put the correct pixels
	env->minimap.mm_height = (env->map.height * SIZE);
	env->minimap.mm_width = (env->map.width * SIZE);
	env->minimap.size = env->minimap.mm_width * env->minimap.mm_height;
	env->minimap.px = malloc(env->minimap.size * sizeof(int));
	if (!env->minimap.px)
		return (puterr("Error\nMemory allocation error when allocating minimap.", NULL));
	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '1')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, WALL_COLOR);
			if (env->mapc[x + y * env->map.width] == '0')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, env->map.floor_color);
			if (env->mapc[x + y * env->map.width] == ' ')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, 0x0);
			x++;
		}
		y++;
	}
	return (0);
}

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
	if (init_minimap(env))
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
