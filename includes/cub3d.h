/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:41:51 by saeby             #+#    #+#             */
/*   Updated: 2023/03/02 18:33:04 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_W 1920
# define WIN_H 1080
# define WIN_NAME "Cub3D"
# define SIZE 50
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5
# include "libft.h"
# include "mlx.h"
# include "structures.h"

// -----------------------------------------------------------------------
// src/main.c
// -----------------------------------------------------------------------
int		render(t_env *env);

// -----------------------------------------------------------------------
// src/init.c
// -----------------------------------------------------------------------
int		init_cub3d(t_env *env);
int		get_map_information(t_env *env);

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
// src/helpers.c
// -----------------------------------------------------------------------
char	*set_spaces(char *line, t_env *env);
void	print_map(t_env *env);

// -----------------------------------------------------------------------
// src/draw.c
// -----------------------------------------------------------------------
void	put_px(t_env *env, t_v2 v, int color);
void	draw_pt(t_env *env, t_v2 v, int color);

#endif