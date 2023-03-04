/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:02 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 17:52:44 by saeby            ###   ########.fr       */
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
	draw_floor(env);
	draw_ceil(env);
	render_minimap(env);
	raycasting(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->minimap > 0)
		mlx_put_image_to_window(env->mlx, env->win, env->img2, 0, 0);
	return (0);
}
