/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:23:38 by saeby             #+#    #+#             */
/*   Updated: 2023/03/05 14:23:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 53)
		close_window(env);
	else if (keycode == 13 || keycode == 126)
		forward(env);
	else if (keycode == 1 || keycode == 125)
		backward(env);
	else if (keycode == 0 || keycode == 123)
		rotate_cc(env);
	else if (keycode == 2 || keycode == 124)
		rotate_c(env);
	else if (keycode == 46)
		toggle_map(env);
	else if (keycode == 18)
		env->texture_id = 0;
	else if (keycode == 19)
		env->texture_id = 1;
	else if (keycode == 20)
		env->texture_id = 2;
	else if (keycode == 21)
		env->texture_id = 3;
	else
		ft_printf("Key: %d\n", keycode);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) mousecode;
	(void) x;
	(void) y;
	(void) env;
	//ft_printf("Mouse: %d, x: %d\n", mousecode, x);
	return (0);
}

int	close_window(t_env *env)
{
	(void) env;
	write(2, "Exiting cub3d\n", 15);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}
