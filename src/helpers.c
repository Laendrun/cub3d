/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:08:54 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:29:06 by saeby            ###   ########.fr       */
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

	// check string format before converting
	// should be like 100,100,100
int	convert_color(t_env *env)
{
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
