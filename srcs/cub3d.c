/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:44:36 by thomathi          #+#    #+#             */
/*   Updated: 2022/11/02 15:27:04 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int checking;

	// regarde si une map est bien passé en argument
	if (argc < 2)
	{
		printf("Il manque une map connard\n");
		return (1);
	}
	// vérifie que la map est bonne (y'a pas toutes les vérifications)
	checking = check_all(argv[1]);
	if (checking != 0)
		return (checking);

	// lance la fonction d'initialisation
	game_init(argv[1]);
	return (0);
}
