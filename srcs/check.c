/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:48:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/11/02 14:36:18 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_files(char *file)
{
	int taille;

	taille = 0;
	while (file[++taille]);
	if (file[taille-1] != 'b')
		return (0);
	if (file[taille-2] != 'u')
		return (0);
	if (file[taille-3] != 'c')
		return (0);
	return (1);
}

int check_textures(char *file)
{
	int fd;
	char *line;
	int checking;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	checking = 0;
	while (line)
	{
		if (line[0] == 'N' && line[1] == 'O')
			checking++;
		else if (line[0] == 'S' && line[1] == 'O')
			checking++;
		else if (line[0] == 'W' && line[1] == 'E')
			checking++;
		else if (line[0] == 'E' && line[1] == 'A')
			checking++;
		line = get_next_line(fd);
	}
	if (checking != 4)
		return (1);
	return (0);
}

int check_colors(char *file)
{
	int fd;
	char *line;
	int checking;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	checking = 0;
	while (line)
	{
		if (line[0] == 'F')
			checking++;
		else if (line[0] == 'C')
			checking++;
		line = get_next_line(fd);
	}
	if (checking != 2)
		return (1);
	return (0);
}

int check_all(char *file)
{
	int fd;
	if (!check_files(file))
	{
		printf("Mauvais nom de fichier\n");
		return (2);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Le fichier n'a pas été trouvé\n");
		return (3);
	}
	if (check_textures(file))
	{
		printf("Il manque des textures\n");
		close(fd);
		return (4);
	}
	if (check_colors(file))
	{
		printf("Il manque des couleurs\n");
		close(fd);
		return (5);
	}
	return (0);
}
