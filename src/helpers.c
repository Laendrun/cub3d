/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:08:54 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 00:18:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_path(int dir, char *line, t_env *env)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (dir == NO)
	{
		env->map.no_path = ft_strdup(tmp[1]);
		env->map.no_path[ft_strlen(env->map.no_path) - 1] = 0;
	}
	else if (dir == SO)
	{
		env->map.so_path = ft_strdup(tmp[1]);
		env->map.so_path[ft_strlen(env->map.so_path) - 1] = 0;
	}
	else if (dir == WE)
	{
		env->map.we_path = ft_strdup(tmp[1]);
		env->map.we_path[ft_strlen(env->map.we_path) - 1] = 0;
	}
	else if (dir == EA)
	{
		env->map.ea_path = ft_strdup(tmp[1]);
		env->map.ea_path[ft_strlen(env->map.ea_path) - 1] = 0;
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (0);
}

int	get_color(int dir, char *line, t_env *env)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (dir == F)
	{
		env->map.f_color = ft_strdup(tmp[1]);
		env->map.f_color[ft_strlen(env->map.f_color) - 1] = 0;
	}
	else if (dir == C)
	{
		env->map.c_color = ft_strdup(tmp[1]);
		env->map.c_color[ft_strlen(env->map.c_color) - 1] = 0;
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (0);
}

int	convert_color(t_env *env)
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
	env->map.floor = (comp[0] << 16) | (comp[1] << 8) | comp[2];
	tmp = ft_split(env->map.c_color, ',');
	comp[0] = ft_atoi(tmp[0]);
	comp[1] = ft_atoi(tmp[1]);
	comp[2] = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	env->map.ceiling = (comp[0] << 16) | (comp[1] << 8) | comp[2];
	return (0);
}

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

int	is_dir(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

int	set_start(t_v2 v, t_env *env)
{
	int	tmp;

	if (env->player.pos.x != 0 || env->player.pos.y != 0)
		return (puterr("Error\nMultiple start position found on map.", NULL));
	env->player.pos.x = v.x * SIZE;
	env->player.pos.y = v.y * SIZE;
	*env->px = v.x * SIZE;
	*env->py = v.y * SIZE;
	tmp = env->mapc[(int)(v.x + v.y * env->map.width)];
	env->mapc[(int)(v.x + v.y * env->map.width)] = '0';
	if (tmp == 'N')
		env->player.s_angle = 270;
	else if (tmp == 'E')
		env->player.s_angle = 0;
	else if (tmp == 'S')
		env->player.s_angle = 90;
	else if (tmp == 'W')
		env->player.s_angle = 180;
	env->player.c_angle = env->player.s_angle;
	return (0);
}

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
			env->map2d.px[(int)((v.x + i) + (v.y + j) * (env->map.width * SIZE))] = color;
			j++;
		}
		i++;
	}
}

int	shade(int color, float distance)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) * (1 - distance / 255.0);
	g = get_g(color) * (1 - distance / 255.0);
	b = get_b(color) * (1 - distance / 255.0);
	//printf("R: %d, G: %d, B: %d\n", r, g, b);
	return (create_rgb(r, g, b));
}

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	create_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}
