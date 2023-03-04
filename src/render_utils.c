/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:23:57 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 14:43:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_mm_px(t_env *env, t_v2 v, int color)
{
	char	*dst;

	if (v.x >= 0 && v.x < env->map2d.width && v.y >= 0 && \
			v.y < env->map2d.height)
	{
		dst = env->addr2 + ((int)v.y * env->line_len2 \
									+ (int)v.x * (env->bpp2 / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_mm_line(t_env *env, t_v4 v4, int col)
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
		put_mm_px(env, (t_v2){v.x, v.y}, col);
		v.x = v.x + delta.x;
		v.y = v.y + delta.y;
		v.z++;
	}
}

void	render_minimap(t_env *env)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < env->map2d.height)
	{
		x = 0;
		while (x < env->map2d.width)
		{
			put_mm_px(env, (t_v2){x, y}, \
				env->map2d.px[x + y * env->map2d.width]);
			x++;
		}
		y++;
	}
	put_mm_px(env, env->player.pos, 0x00FF00);
}