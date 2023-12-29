/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:22:18 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/27 16:45:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_image_to_window(t_all *a)
{
	a->matrix->y = 0;
	while (a->matrix->matrix[a->matrix->y])
	{
		a->matrix->x = 0;
		while (a->matrix->matrix[a->matrix->y][a->matrix->x] != '\0')
		{
			if (a->matrix->matrix[a->matrix->y][a->matrix->x] != '\n')
				mlx_image_to_window(a->map->window, a->map->img[BACK],
					a->matrix->x * (a->map->s_x), a->matrix->y * (a->map->s_y));
			if (a->matrix->matrix[a->matrix->y][a->matrix->x] == '1')
				mlx_image_to_window(a->map->window, a->map->img[WALL],
					a->matrix->x * (a->map->s_x), a->matrix->y * (a->map->s_y));
			else if (a->matrix->matrix[a->matrix->y][a->matrix->x] == 'P')
				mlx_image_to_window(a->map->window, a->map->img[HERO],
					a->matrix->x * (a->map->s_x), a->matrix->y * (a->map->s_y));
			else if (a->matrix->matrix[a->matrix->y][a->matrix->x] == 'C')
				mlx_image_to_window(a->map->window, a->map->img[COLLECT],
					a->matrix->x * (a->map->s_x), a->matrix->y * (a->map->s_y));
			else if (a->matrix->matrix[a->matrix->y][a->matrix->x] == 'E')
				mlx_image_to_window(a->map->window, a->map->img[EXIT],
					a->matrix->x * (a->map->s_x), a->matrix->y * (a->map->s_y));
			a->matrix->x++;
		}
		a->matrix->y++;
	}
}
