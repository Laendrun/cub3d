/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:58 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 17:51:35 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_v2
{
	float		x;
	float		y;
}				t_v2;

typedef struct s_v3
{
	float		x;
	float		y;
	float		z;
}				t_v3;

typedef struct s_v4
{
	float		a;
	float		b;
	float		c;
	float		d;
}				t_v4;

typedef struct s_proj
{
	size_t		width;
	size_t		height;
	size_t		half_width;
	size_t		half_height;
	int			scale;
}				t_proj;

typedef struct s_raycast
{
	float		a_i;
}				t_raycast;

typedef struct s_ray
{
	float	angle;
	size_t	count;
	float	cos;
	float	sin;
	int		wall;
	float	wall_h;
	float	dist;
	t_v2	pos;
}			t_ray;

typedef struct s_player
{
	float		angle;
	float		fov;
	float		halffov;
	t_v2		pos;
}				t_player;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_map
{
	char		*path;
	char		*no_path;
	t_texture	no_sp;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			ceiling;
	int			floor;
	int			wall;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_map2d
{
	int			*px;
	size_t		width;
	size_t		height;
	size_t		size;
}				t_map2d;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*img2;
	char		*addr2;
	int			bpp2;
	int			line_len2;
	int			endian2;
	char		*mapc;
	int			minimap;
	t_map		map;
	t_map2d		map2d;
	t_player	player;
	t_raycast	raycast;
	t_proj		proj;
}				t_env;

#endif