/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:24:14 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 20:54:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_information(t_env *env)
{
	int		fd;
	char	*line;

	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (puterr("Error\nUnable to open map: ", env->map.path));
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO", 2) \
				&& ft_strncmp(line, "SO", 2) \
				&& ft_strncmp(line, "WE", 2) \
				&& ft_strncmp(line, "EA", 2) \
				&& ft_strncmp(line, "F", 1) \
				&& ft_strncmp(line, "C", 1))
		{
			free(line);
			break ;
		}
		ft_printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
