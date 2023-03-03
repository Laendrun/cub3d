/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:41:51 by saeby             #+#    #+#             */
/*   Updated: 2023/03/03 18:09:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "structures.h"
# define WIN_W 640
# define WIN_H 480
# define WIN_NAME "Cub3D"
# define WIN2_NAME "Cub2D"
# define FOV 30.0
# define SIZE 10
# define PLAYER_SIZE 4
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5
# define WALL_COLOR 0xFFFFFF
# define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
# define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

// test.c
void	ray_casting(t_env *env);

// -----------------------------------------------------------------------
// src/main.c
// -----------------------------------------------------------------------
int		render(t_env *env);

// -----------------------------------------------------------------------
// src/cast.c
// -----------------------------------------------------------------------
int		touch_wall(t_env *env, t_v2 v);
void	cast_ray(t_env *env);

// -----------------------------------------------------------------------
// src/init.c
// -----------------------------------------------------------------------
int		init_cub3d(t_env *env);
int		get_map_information(t_env *env);
int		set_start(t_v2 v, t_env *env);
void	fill_pt(t_env *env, t_v2 v, int color);
int		init_minimap(t_env *env);

// -----------------------------------------------------------------------
// src/hooks.c
// -----------------------------------------------------------------------
int		close_window(t_env *env);
int		mouse_handler(int mousecode, int x, int y, t_env *env);
int		key_handler(int keycode, t_env *env);

// -----------------------------------------------------------------------
// src/hooks.c
// -----------------------------------------------------------------------
int		puterr(char *s1, char *s2);

// -----------------------------------------------------------------------
// src/parse.c
// -----------------------------------------------------------------------
int		parse_information(t_env *env);
int		get_texture_path(int dir, char *line, t_env *env);
int		get_color(int dir, char *line, t_env *env);
int		check_line(char *line, int *fd, t_env *env);
int		fill_map(t_env *env);

// -----------------------------------------------------------------------
// src/player_move.c
// -----------------------------------------------------------------------
void	forward(t_env * env);
void	backward(t_env * env);
void	rotate_cc(t_env *env);
void	rotate_c(t_env *env);

// -----------------------------------------------------------------------
// src/helpers.c
// -----------------------------------------------------------------------
char	*set_spaces(char *line, t_env *env);
void	print_map(t_env *env);
int		convert_colors(t_env *env);
float	distance(t_v2 player, t_v2 wall);

// -----------------------------------------------------------------------
// src/check.c
// -----------------------------------------------------------------------
int	check_map(t_env *env);

// -----------------------------------------------------------------------
// src/draw.c
// -----------------------------------------------------------------------
void	put_px(t_env *env, t_v2 v, int color, int win);
void	draw_pt(t_env *env, t_v2 v, int color, int win);
void	draw_player(t_env *env, t_v2 v, int color, int win);
void	draw_floor(t_env *env);
void	draw_ceiling(t_env *env);
void	ft_draw_line(t_env *env, t_v4 v4, int col, int win);
//void	ft_draw_line(t_env *env, t_v2 s, t_v2 e, int col);

// -----------------------------------------------------------------------
// src/is.c
// -----------------------------------------------------------------------
int		is_dir(char c);

#endif