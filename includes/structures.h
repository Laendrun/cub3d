/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:44:22 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 20:39:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_v2
{
	size_t	x;
	size_t	y;
}				t_v2;

typedef struct s_player
{
	t_v2	pos;
	int		s_dir; // N:78, E:69, S:83, W:87
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
	t_map		map;
	t_player	player;
}				t_env;

#endif