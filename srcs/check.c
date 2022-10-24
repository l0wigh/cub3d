/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:48:56 by thomathi          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:20 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
