/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:54:20 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 21:50:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_env *env)
{
	(void) env;
	if (keycode == 53)
		close_window(env);
	else if (keycode == 13)
		forward(env);
	else if (keycode == 1)
		backward(env);
	else if (keycode == 0)
		rotate_cc(env);
	else if (keycode == 2)
		rotate_c(env);
	else
		ft_printf("Key: %d\n", keycode);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	(void) env;
	ft_printf("Mouse: %d\n", mousecode);
	return (0);
}

int	close_window(t_env *env)
{
	write(2, "Exiting cub3d\n", 15);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}
