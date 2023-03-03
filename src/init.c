/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:57:04 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 23:59:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_cub3d(t_env *env)
{
	int	fd;

	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (puterr("Error\nUnable to open map: ", env->map.path));
	close(fd);
	if (init_env(env))
		return (1);
	if (init_map(env))
		return (1);
	// print_map(env);
	if (init_mlx(env))
		return (1);
	return (0);
}

int	init_map(t_env *env)
{
	if (parse_textures(env))
		return (1);
	if (convert_color(env))
		return (1);
	if (get_map_info(env))
		return (1);
	env->mapc = ft_calloc((env->map.width * env->map.height), sizeof(char));
	if (!env->mapc)
		return (puterr("Error\nMemory allocation error.\n", NULL));
	if (fill_map(env))
		return (1);
	if (check_map(env))
		return (1);
	if (init_map2d(env))
		return (1);
	return (0);
}

int	init_env(t_env *env)
{
	env->px = malloc(sizeof(float));
	env->py = malloc(sizeof(float));
	env->map.width = 0;
	env->map.height = 0;
	env->map.ceiling = 0;
	env->map.floor = 0;
	env->map.wall = 0xFFFFFF;
	env->player.pos.x = 0;
	env->player.pos.y = 0;
	env->player.fov = FOV;
	env->player.halffov = FOV / 2;
	return (0);
}

int	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, WIN_NAME);
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, \
									&env->line_len, &env->endian);
	env->win2 = mlx_new_window(env->mlx, env->map.width * SIZE, env->map.height * SIZE, WIN2_NAME);
	env->img2 = mlx_new_image(env->mlx, env->map.width * SIZE, env->map.height * SIZE);
	env->addr2 = mlx_get_data_addr(env->img2, &env->bpp2, \
									&env->line_len2, &env->endian2);
	mlx_hook(env->win, 4, 0, mouse_handler, env);
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
	mlx_hook(env->win, 17, 1L << 0, close_window, env);
	mlx_hook(env->win2, 2, 1L << 0, key_handler, env);
	mlx_hook(env->win2, 17, 1L << 0, close_window, env);
	return (0);
}

int	init_map2d(t_env *env)
{
	size_t	x;
	size_t	y;

	env->map2d.height = (env->map.height * SIZE);
	env->map2d.width = (env->map.width * SIZE);
	env->map2d.size = env->map2d.width * env->map2d.height;
	env->map2d.px = (int *) malloc(env->map2d.size * sizeof(int));
	if (!env->map2d.px)
		return (puterr("Error\nMemory allocation error when allocating 2D map.", NULL));
	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->mapc[x + y * env->map.width] == '1')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, WALL);
			if (env->mapc[x + y * env->map.width] == '0')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, env->map.floor);
			if (env->mapc[x + y * env->map.width] == ' ')
				fill_pt(env, (t_v2){x * SIZE, y * SIZE}, 0x0);
			x++;
		}
		y++;
	}
	return (0);
}
