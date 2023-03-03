/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:24:14 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 18:50:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# include <stdio.h>

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
		env->map.c_color[ft_strlen(env->map.f_color) - 1] = 0;
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (0);
}

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

int	parse_information(t_env *env)
{
	int		fd;
	char	*line;

	fd = open(env->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2))
			if (get_texture_path(NO, line, env))
				return (1);
		if (!ft_strncmp(line, "SO", 2))
			if (get_texture_path(SO, line, env))
				return (1);
		if (!ft_strncmp(line, "EA", 2))
			if (get_texture_path(EA, line, env))
				return (1);
		if (!ft_strncmp(line, "WE", 2))
			if (get_texture_path(WE, line, env))
				return (1);
		if (!ft_strncmp(line, "F", 1))
			if (get_color(F, line, env))
				return (1);
		if (!ft_strncmp(line, "C", 1))
			if (get_color(C, line, env))
				return (1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_line(char *line, int *fd, t_env *env)
{
	(void) fd;
	while (*line)
	{
		if (!(*line == '0' || *line == '1' || *line == 'N' || \
			*line == 'S' || *line == 'W' || *line == 'E' || *line == ' '))
		{
			//free(line);
			//close(*fd);
			return (puterr("Error\nParsing: map contains unauthorized characters.", NULL));
		}
		if (ft_strlen(line) >= env->map.width)
			env->map.width = ft_strlen(line);
		line++;
	}
	return (0);
}

int	fill_map(t_env *env)
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
		tmp = env->mapc;
		if (ft_strlen(line) < env->map.width)
			line = set_spaces(line, env);
		env->mapc = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
