/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:54:20 by saeby             #+#    #+#             */
/*   Updated: 2023/03/01 20:53:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_env *env)
{
	(void) env;
	if (keycode == 53)
		close_window(env);
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
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}
