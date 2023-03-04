/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:25:38 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:26:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	shade(int color, float distance)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) * (1 - distance / 255.0);
	g = get_g(color) * (1 - distance / 255.0);
	b = get_b(color) * (1 - distance / 255.0);
	return (create_rgb(r, g, b));
}

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	create_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}
