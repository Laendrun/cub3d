/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:59:16 by saeby             #+#    #+#             */
/*   Updated: 2023/03/05 13:54:36 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_projection(t_env *env)
{
	env->proj.scale = 1;
	env->proj.width = WIN_W / env->proj.scale;
	env->proj.height = WIN_H / env->proj.scale;
	env->proj.half_width = env->proj.width / 2;
	env->proj.half_height = env->proj.height / 2;
	return (0);
}

int	init_sprite(t_env *env)
{
	env->map.textures[0].img = mlx_xpm_file_to_image(env->mlx, env->map.no_path, &(env->map.textures[0].width), &(env->map.textures[0].height));
	env->map.textures[0].addr = (char *)mlx_get_data_addr(env->map.textures[0].img, &env->map.textures[0].bpp, &env->map.textures[0].line_len, &env->map.textures[0].endian);
	env->map.textures[1].img = mlx_xpm_file_to_image(env->mlx, env->map.ea_path, &(env->map.textures[1].width), &(env->map.textures[1].height));
	env->map.textures[1].addr = (char *)mlx_get_data_addr(env->map.textures[1].img, &env->map.textures[1].bpp, &env->map.textures[1].line_len, &env->map.textures[1].endian);
	env->map.textures[2].img = mlx_xpm_file_to_image(env->mlx, env->map.so_path, &(env->map.textures[2].width), &(env->map.textures[2].height));
	env->map.textures[2].addr = (char *)mlx_get_data_addr(env->map.textures[2].img, &env->map.textures[2].bpp, &env->map.textures[2].line_len, &env->map.textures[2].endian);
	env->map.textures[3].img = mlx_xpm_file_to_image(env->mlx, env->map.we_path, &(env->map.textures[3].width), &(env->map.textures[3].height));
	env->map.textures[3].addr = (char *)mlx_get_data_addr(env->map.textures[3].img, &env->map.textures[3].bpp, &env->map.textures[3].line_len, &env->map.textures[3].endian);
	return (0);
}
