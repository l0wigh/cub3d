/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:46:22 by thomathi          #+#    #+#             */
/*   Updated: 2022/11/02 15:48:47 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../minilibx/mlx.h"

typedef struct s_cub
{
	char	*map_file;
	int		*mlx;
	int		*win;
	int		*img_ptr;
	int		res_x;
	int		res_y;
	int		map_fd;
}	t_cub;

typedef struct s_map
{
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	// vision du joueur
	char	*dir;
}	t_player;

// check.c
int		check_files(char *file);
int		check_textures(char *file);
int		check_colors(char *file);
int		check_all(char *file);

// init.c
void	game_init(char *file);

// loop.c
void	game_loop(t_cub *cub);
#endif
