/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:44:22 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 15:10:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_v2
{
	float	x;
	float	y;
}				t_v2;

typedef struct s_v3
{
	float	x;
	float	y;
	float	z;
}				t_v3;

typedef struct s_v4
{
	float	a;
	float	b;
	float	c;
	float	d;
}				t_v4;

typedef struct s_player
{
	t_v2	pos;
	int		s_dir; // N:78, E:69, S:83, W:87 - starting direction
	int		c_dir; // N:78, E:69, S:83, W:87 - current direction
}				t_player;

typedef struct s_map
{
	char		*path;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			ceiling_color;
	int			floor_color;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_minimap
{
	int			*px;
	int			mm_width;
	int			mm_height;
	int			size;
}				t_minimap;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*win2;
	void		*img2;
	char		*addr2;
	int			bpp2;
	int			line_len2;
	int			endian2;
	char		*mapc;
	float		dist;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
}				t_env;

#endif