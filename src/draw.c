/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:30:39 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 14:29:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_px(t_env *env, t_v2 v, int color)
{
	char	*dst;

	if (v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
	{
		dst = env->addr + ((int)v.y * env->line_len \
									+ (int)v.x * (env->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_line(t_env *env, t_v4 v4, int col)
{
	float	step;
	t_v3	v;
	t_v2	delta;

	delta.x = v4.c - v4.a;
	delta.y = v4.d - v4.b;
	if (fabsf(delta.x) >= fabsf(delta.y))
		step = fabsf(delta.x);
	else
		step = fabsf(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	v.x = v4.a;
	v.y = v4.b;
	v.z = 0;
	while (v.z < step)
	{
		put_px(env, (t_v2){v.x, v.y}, col);
		v.x = v.x + delta.x;
		v.y = v.y + delta.y;
		v.z++;
	}
}

void	draw_floor(t_env *env)
{
	size_t	x;
	size_t	y;

	y = WIN_H / 2;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_px(env, (t_v2){x, y}, env->map.floor);
			x++;
		}
		y++;
	}
}

void	draw_ceil(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_px(env, (t_v2){x, y}, env->map.ceiling);
			x++;
		}
		y++;
	}
}
