/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:37:46 by thomathi          #+#    #+#             */
/*   Updated: 2022/11/02 15:33:23 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// fonction temporaire pour tester
int exiting_mouse(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}

int	game_keys(int code, t_cub *cub)
{
	// à changer
	if (code == 53)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		exit(0);
	}
	// pour plus tard
	/* if (code == 13) */
	/* 	cub->player->move_up = 1; */
	/* if (code == 1) */
	/* 	cub->player->move_down = 1; */
	/* if (code == 0) */
	/* 	cub->player->move_left = 1; */
	/* if (code == 2) */
	/* 	cub->player->move_right = 1; */
	/* if (code == 123) */
	/* 	cub->player->turn_left = 1; */
	/* if (code == 124) */
	/* 	cub->player->turn_right = 1; */
	return (0);
}

void	game_mlx_init(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->res_x, cub->res_y, "Cub3D");
}

void game_init(char *map)
{
	t_cub *cub;

	cub = malloc(sizeof(t_cub));
	cub->res_x = 1280;
	cub->res_y = 800;
	cub->map_file = malloc(sizeof (char *));
	cub->map_file = map;
	game_mlx_init(cub);
	mlx_key_hook(cub->win, game_keys, cub);
	mlx_hook(cub->win, 17, 0, exiting_mouse, cub);
	game_loop(cub);
}
