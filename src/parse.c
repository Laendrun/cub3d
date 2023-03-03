/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:04:52 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 21:01:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures(t_env *env)
{
	int		fd;
	char	*line;

	fd = open(env->map.path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
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
	}
	return (0);
}

int	get_map_info(t_env *env)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(env->map.path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!(!ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "NO", 2) || \
					!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) || \
					!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1) || \
					!ft_strncmp(line, "\n", 1)))
			break ;
		free(line);
	}
	while (1)
	{
		tmp = line;
		line = ft_strtrim(line, "\n");
		free(tmp);
		if (line_nok(line, env))
		{
			close(fd);
			free(line);
			return (1);
		}
		free(line);
		env->map.height++;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
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
	while (1)
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
		if (!line)
			break ;
	}
	close (fd);
	return (0);
}
