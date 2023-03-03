/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:55:43 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 22:38:06 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_px(t_env *env, t_v2 v, int color, int win)
{
	char	*dst;

	if (win == 1 && v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
	{
		dst = env->addr + ((int)v.y * env->line_len \
									+ (int)v.x * (env->bpp / 8));
		*(unsigned int *)dst = color;
	}
	if (win == 2 && v.x >= 0 && v.x < env->map.width * SIZE && v.y >= 0 && v.y < env->map.height * SIZE)
	{
		dst = env->addr2 + ((int)v.y * env->line_len2 \
									+ (int)v.x * (env->bpp2 / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_pt(t_env *env, t_v2 v, int color, int win)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			put_px(env, (t_v2){v.x + i, v.y + j}, color, win);
			j++;
		}
		i++;
	}
}

void	draw_player(t_env *env, t_v2 v, int color, int win)
{
	int	i;
	int	j;

	i = - PLAYER_SIZE / 2;
	while (i < PLAYER_SIZE / 2)
	{
		j = - PLAYER_SIZE / 2;
		while (j < PLAYER_SIZE / 2)
		{
			put_px(env, (t_v2){v.x + i, v.y + j}, color, win);
			j++;
		}
		i++;
	}
}

void	ft_draw_line(t_env *env, t_v2 s, t_v2 e, int col)
{
	float		step;
	t_v3	v;
	t_fv2	delta;

	delta.x = e.x - s.x;
	delta.y = e.y - s.y;
	if (fabsf(delta.x) >= fabsf(delta.y))
		step = fabsf(delta.x);
	else
		step = fabsf(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	v.x = s.x;
	v.y = s.y;
	v.z = 0;
	while (v.z < step)
	{
		put_px(env, (t_v2){v.x, v.y}, col, 2);
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
			put_px(env, (t_v2){x, y}, env->map.floor_color, 1);
			x++;
		}
		y++;
	}
}

void	draw_ceiling(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_px(env, (t_v2){x, y}, env->map.ceiling_color, 1);
			x++;
		}
		y++;
	}
}
