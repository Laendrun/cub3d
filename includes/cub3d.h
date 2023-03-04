/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:44:23 by saeby             #+#    #+#             */
/*   Updated: 2023/03/04 13:27:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
#include <stdio.h>
# define NO 0
# define EA 1
# define SO 2
# define WE 3
# define F 4
# define C 5
# define WIN_W 1280
# define WIN_H 720
# define SIZE 20
# define WALL 0x00FFFFFF
# define WIN_NAME "Cub3D"
# define WIN2_NAME "Cub2D"
# define FOV 60.0
# define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
# define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)
# include "libft.h"
# include "mlx.h"
# include "structures.h"

// ------------------------------------
// src/main.c
// ------------------------------------
int		render(t_env *env);

// ------------------------------------
// src/cast.c
// ------------------------------------
void	raycasting(t_env *env);

// ------------------------------------
// src/error.c
// ------------------------------------
int		puterr(char *s1, char *s2);

// ------------------------------------
// src/map_error.c
// ------------------------------------
int		check_map(t_env *env);

// ------------------------------------
// src/line_error.c
// ------------------------------------
int		line_nok(char *line, t_env *env);
int		space_around(t_v2 v, t_env *env);

// ------------------------------------
// src/color.c
// ------------------------------------
int		shade(int color, float distance);
int		create_rgb(int r, int g, int b);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);

// ------------------------------------
// src/init.c
// ------------------------------------
int		init_cub3d(t_env *env);
int		init_env(t_env *env);
int		init_mlx(t_env *env);
int		init_map(t_env *env);
int		init_map2d(t_env *env);

// ------------------------------------
// src/hooks.c
// ------------------------------------
int		key_handler(int keycode, t_env *env);
int		mouse_handler(int mousecode, int x, int y, t_env *env);
int		close_window(t_env *env);

// ------------------------------------
// src/player_moves.c
// ------------------------------------
void	forward(t_env * env);
void	backward(t_env *env);
void	rotate_c(t_env *env);
void	rotate_cc(t_env *env);

// ------------------------------------
// src/parse.c
// ------------------------------------
int		parse_textures(t_env *env);
int		get_map_info(t_env *env);
int		fill_map(t_env *env);

// ------------------------------------
// src/helpers.c
// ------------------------------------
int		get_texture_path(int card, char *line, t_env *env);
int		get_color(int dir, char *line, t_env *env);
int		convert_color(t_env *env);
char	*set_spaces(char *line, t_env *env);
int		is_dir(char c);

// ------------------------------------
// src/init_helpers.c
// ------------------------------------
int		set_start(t_v2 v, t_env *env);
void	fill_pt(t_env *env, t_v2 v, int color);
void	fill_map2d(t_env *env, t_v2 v);

// ------------------------------------
// src/draw.c
// ------------------------------------
void	put_px(t_env *env, t_v2 v, int color, int win);
void	draw_line(t_env *env, t_v4 v4, int col, int win);
void	draw_ceil(t_env *env);
void	draw_floor(t_env *env);

// ------------------------------------
// src/debug.c
// ------------------------------------
void	print_map(t_env *env);

#endif