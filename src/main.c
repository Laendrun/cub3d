/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:54 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 20:54:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_env	env;

	(void) av;
	if (ac != 2)
		return (puterr("Wrong number of arguments. ", \
						"Usage ./cub3d <map.cub>"));
	env.map.path = av[1];
	if (parse_information(&env))
		return (1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bpp, \
									&env.line_len, &env.endian);
	mlx_hook(env.win, 4, 0, mouse_handler, &env);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

int	render(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
