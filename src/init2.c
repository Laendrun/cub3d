/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:59:16 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 17:39:50 by saeby            ###   ########.fr       */
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
	env->map.no_sp.img = mlx_xpm_file_to_image(env->mlx, env->map.no_path, &(env->map.no_sp.width), &(env->map.no_sp.height));
	env->map.no_sp.addr = (char *)mlx_get_data_addr(env->map.no_sp.img, &env->map.no_sp.bpp, &env->map.no_sp.line_len, &env->map.no_sp.endian);
	return (0);
}
