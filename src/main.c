/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:02 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 12:45:31 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (puterr("Wrong number of arguments. Usage ./cub3d <map.cub>", \
				0));
	env.map.path = av[1];
	if (init_cub3d(&env))
		return (1);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

int	render(t_env *env)
{
	size_t	x;
	size_t	y;

	draw_floor(env);
	draw_ceil(env);
	y = 0;
	while (y < env->map2d.height)
	{
		x = 0;
		while (x < env->map2d.width)
		{
			put_px(env, (t_v2){x, y}, \
				env->map2d.px[x + y * env->map2d.width], 2);
			x++;
		}
		y++;
	}
	raycasting(env);
	put_px(env, env->player.pos, 0x00FF00, 2);
	mlx_put_image_to_window(env->mlx, env->win2, env->img2, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
