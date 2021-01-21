/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:54:17 by namenega          #+#    #+#             */
/*   Updated: 2021/01/21 17:28:35 by jbodson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"
# include "../includes/mlx/mlx.h"
# include "../includes/libft/libft.h"
# include "get_next_line.h"
# define R 0x00FF0000
# define G 0x0000FF00
# define B 0x000000FF

typedef struct	s_data
{
	int			width;
	int			height;
	int			width_verif;
	int			height_verif;
	int			r_sky;
	int			g_sky;
	int			b_sky;
	int			r_ground;
	int			g_ground;
	int			b_ground;
	char		*path_sprite;
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_west;
	int			r_sky_verif;
	int			g_sky_verif;
	int			b_sky_verif;
	int			r_ground_verif;
	int			g_ground_verif;
	int			b_ground_verif;
	int			path_sprite_verif;
	int			path_north_verif;
	int			path_south_verif;
	int			path_east_verif;
	int			path_west_verif;
	void		*mlx_ptr;
	void		*mlx_win;
	int			**map;
	int			parsed;
	int			line_map;
	int			widthmap;
	t_list		*lst_line;
	t_list		*firsttoken;
}				t_data;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_pos
{
	t_vec		pos;
	t_vec		dir;
	t_vec		plane_cam;
	t_vec		camera;
	double		ttime;
	double		oldtime;
}				t_pos;

typedef struct	s_ray
{
	t_vec		dir;
}				t_ray;

/*
** PARSING/MAIN.C
*/

int					main(int ac, char const **av);
int					ft_error_msg(char *s);
void				ft_error_exit(char *s);

/*
** PARSING/PARSING.C
*/

t_data				*ft_data(char *file, int ac);
int					ft_get_data(t_data *data, char *file);
int					ft_gnl(int fd, char *line, t_data *data);
int					ft_parsing_data(t_list *el, t_data *data);

/*
** PARSING/SPRITES_PATH/RESOLUTION.C
*/

int					ft_resolution(t_data *data, char *line);
void				ft_error_resolution_1(char *line);
unsigned long int	ft_uli_error(const char *line);
void				ft_error_resolution_3(char *line);
void				ft_error_resolution_4(char *line);

/*
** PARSING/SPRITES_PATH/OBSTACLE.C
*/

int					ft_sprite(t_data *data, char *line);

/*
** PARSING/SPRITES_PATH/SKY.C
*/

int					ft_color_sky(t_data *data, char *line);
void				ft_error_skyground_1(char *line);
void				ft_error_skyground_3(char *line);
void				ft_error_skyground_4(char *line);
t_data				*ft_error_skyg_2(t_data *data);

/*
** PARSING/SPRITES_PATH/GROUND.C
*/

int					ft_color_ground(t_data *data, char *line);
t_data				*ft_error_ground(t_data *data);
void				ft_error_skyground_5(t_data *data);

/*
** PARSING/SPRITES_PATH/DIRECTIONS.C
*/

int					ft_north(t_data *data, char *line);
int					ft_south(t_data *data, char *line);
int					ft_west(t_data *data, char *line);
int					ft_east(t_data *data, char *line);

/*
** PARSING/AFFICHAGE.C
*/

int					ft_affichage(t_data *data);

/*
** PARSING/EVENT.C
*/

int					ft_event(t_data *data);
int					ft_exit_hook(void *x);

/*
** PARSING/FREE.C
*/

void				ft_free_data(t_data *data, char *str);

/*
** PARSING/MAP/MAP.C
*/

int					ft_map(t_data *data, t_list *el);
int					ft_verifmap(int **map, int height, int width);
int					ft_verifcharacters(int **map, int height, int width);
int					ft_verifholes(int **map, int height, int width);

#endif
