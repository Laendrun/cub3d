/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:55:43 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 20:02:42 by saeby            ###   ########.fr       */
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