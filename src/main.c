/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:54 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 22:00:12 by saeby            ###   ########.fr       */
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

/*
void	cast_ray(t_env *env)
{
	char	*dst;
	size_t	i;

	i = env->player.pos.y;
	if (env->player.c_dir == 'N')
	{
		dst = env->addr2 + ((int)(env->player.pos.y - i) * env->line_len2 \
									+ (int)env->player.pos.x * (env->bpp2 / 8));
		while (*(unsigned int*)dst != 0xFFFFFF)
		{
			dst = env->addr2 + ((int)(env->player.pos.y - i) * env->line_len2 \
							+ (int)env->player.pos.x * (env->bpp2 / 8));
			i++;
		}
		printf("i: %zu\n", i);
	}
}
*/
int	render(t_env *env)
{
	size_t	x;
	size_t	y;

	// START MINIMAP
	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '1')
				draw_pt(env, (t_v2){x * SIZE, y * SIZE}, 0xFFFFFF, 2);
			if (env->mapc[x + y * env->map.width] == '0')
				draw_pt(env, (t_v2){x * SIZE, y * SIZE}, env->map.floor_color, 2);
			if (env->mapc[x + y * env->map.width] == ' ')
				draw_pt(env, (t_v2){x * SIZE, y * SIZE}, 0x0, 2);
			x++;
		}
		y++;
	}
	draw_player(env, (t_v2){env->player.pos.x, env->player.pos.y}, 0x00FF00, 2);
	// END MINIMAP
	//cast_ray(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win2, env->img2, 0, 0);
	return (0);
}
