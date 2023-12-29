/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:48:25 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 13:28:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_ask_hero_to_me(t_all *a)
{
	int	y;
	int	x;

	y = 0;
	while (a->matrix->matrix[y])
	{
		x = 0;
		while (a->matrix->matrix[y][x] != '\0')
		{
			if (a->matrix->matrix[y][x] == 'P')
			{
				a->hero->x = x;
				a->hero->y = y;
				break ;
			}
			x++;
		}
		if (a->matrix->matrix[y][x] == 'P')
			break ;
		y++;
	}
}

void	ft_move_hero(t_all *a, int up_down, int lef_rig)
{
	if (a->matrix->matrix[a->hero->y + up_down][a->hero->x + lef_rig] != '1')
	{
		if (a->matrix->matrix[a->hero->y + up_down]
			[a->hero->x + lef_rig] == 'C')
			a->items->collect--;
		if (a->matrix->matrix[a->hero->y + up_down]
			[a->hero->x + lef_rig] == 'E' && a->items->collect > 0)
			return ;
		if (a->matrix->matrix[a->hero->y + up_down]
			[a->hero->x + lef_rig] == 'E' && a->items->collect == 0)
		{
			a->items->collect--;
			ft_delete_img_texture_matrix_exit(a);
		}
		ft_refresh(a, up_down, lef_rig);
	}
}

void	ft_refresh(t_all *a, int up_down, int lef_rig)
{
	char	*number;

	a->matrix->matrix[a->hero->y][a->hero->x] = '0';
	a->matrix->matrix[a->hero->y + up_down][a->hero->x + lef_rig] = 'P';
	a->hero->movements++;
	ft_new(a, a->map->s_x * (a->hero->x + lef_rig), a->map->s_y * (a->hero->y + up_down));
	mlx_image_to_window(a->map->window, a->map->img[WALL], 0, 0);
	number = ft_itoa(a->hero->movements);
	mlx_put_string(a->map->window, number, 0, 0);
	ft_printf("%d\n", a->hero->movements);
	free(number);
	a->hero->y += up_down;
	a->hero->x += lef_rig;
}

void	ft_new(t_all *a, int x, int y)
{
	mlx_delete_image(a->map->window, a->map->img[HERO]);
	a->map->img[HERO] = mlx_texture_to_image(a->map->window, a->map->png[HERO]);
	if (!a->map->png[HERO] || !a->map->img[HERO])
		ft_mlx_error();
	mlx_resize_image(a->map->img[HERO], a->map->s_x, a->map->s_y);
	mlx_image_to_window(a->map->window, a->map->img[BACK], x, y);
	mlx_image_to_window(a->map->window, a->map->img[HERO], x, y);
}
