/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:54 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 13:53:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_env	env;

	(void) av;
	if (ac != 2)
		return (puterr("Wrong number of arguments. ", \
						"Usage ./cub3d <map.cub>"));
	env.map.path = av[1];
	if (init_cub3d(&env))
		return (1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bpp, \
									&env.line_len, &env.endian);
	env.win2 = mlx_new_window(env.mlx, env.map.width * SIZE, env.map.height * SIZE, WIN2_NAME);
	env.img2 = mlx_new_image(env.mlx, env.map.width * SIZE, env.map.height * SIZE);
	env.addr2 = mlx_get_data_addr(env.img2, &env.bpp2, \
									&env.line_len2, &env.endian2);
	mlx_hook(env.win, 4, 0, mouse_handler, &env);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	mlx_hook(env.win2, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win2, 17, 1L << 0, close_window, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

void	cast_ray(t_env *env)
{
	size_t	i;

	i = env->player.pos.y / SIZE;
	if (env->player.c_dir == 'N')
	{
		printf("i: %zu\n", i);
	}
}

int	render(t_env *env)
{
	int	x;
	int	y;

	// START MINIMAP
	y = 0;
	while (y < env->minimap.mm_height)
	{
		x = 0;
		while (x < env->minimap.mm_width)
		{
			put_px(env, (t_v2){x, y}, env->minimap.px[x + y * env->minimap.mm_width], 2);
			x++;
		}
		y++;
	}
	draw_player(env, (t_v2){env->player.pos.x, env->player.pos.y}, 0x00FF00, 2);
	// END MINIMAP
	//cast_ray(env);
	draw_floor(env);
	draw_ceiling(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win2, env->img2, 0, 0);
	return (0);
}
