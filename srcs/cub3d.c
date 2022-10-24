/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:44:36 by thomathi          #+#    #+#             */
/*   Updated: 2022/10/24 15:58:50 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int fd;
	if (argc < 2)
	{
		printf("Il manque une map connard\n");
		return (1);
	}
	if (!check_files(argv[1]))
	{
		printf("Mauvais nom de fichier\n");
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Le fichier n'a pas été trouvé\n");
		return (3);
	}
	return (0);
}
