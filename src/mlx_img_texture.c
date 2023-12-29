/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:07:03 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 11:56:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_img_texture(t_all *a)
{
	a->map->png[WALL] = mlx_load_png(PNG_WALL);
	a->map->img[WALL] = mlx_texture_to_image(a->map->window, a->map->png[WALL]);
	if (!a->map->png[WALL] || !a->map->img[WALL])
		ft_mlx_error();
	a->map->png[HERO] = mlx_load_png(PNG_HERO);
	a->map->img[HERO] = mlx_texture_to_image(a->map->window, a->map->png[HERO]);
	if (!a->map->png[HERO] || !a->map->img[HERO])
		ft_mlx_error();
	a->map->png[BACK] = mlx_load_png(PNG_BACK);
	a->map->img[BACK] = mlx_texture_to_image(a->map->window, a->map->png[BACK]);
	if (!a->map->png[BACK] || !a->map->img[BACK])
		ft_mlx_error();
	a->map->png[COLLECT] = mlx_load_png(PNG_COLLECT);
	a->map->img[COLLECT] = mlx_texture_to_image(a->map->window,
			a->map->png[COLLECT]);
	if (!a->map->png[COLLECT] || !a->map->img[COLLECT])
		ft_mlx_error();
	a->map->png[EXIT] = mlx_load_png(PNG_EXIT);
	a->map->img[EXIT] = mlx_texture_to_image(a->map->window, a->map->png[EXIT]);
	if (!a->map->png[EXIT] || !a->map->img[EXIT])
		ft_mlx_error();
	ft_resize_image(a);
}

void	ft_resize_image(t_all *a)
{
	a->map->s_y = HEIGHT / a->matrix->line;
	a->map->s_x = WIDTH / a->matrix->column;
	mlx_resize_image(a->map->img[WALL], a->map->s_x, a->map->s_y);
	mlx_resize_image(a->map->img[HERO], a->map->s_x, a->map->s_y);
	mlx_resize_image(a->map->img[BACK], a->map->s_x, a->map->s_y);
	mlx_resize_image(a->map->img[COLLECT], a->map->s_x, a->map->s_y);
	mlx_resize_image(a->map->img[EXIT], a->map->s_x, a->map->s_y);
}

void	ft_delete_img_texture_matrix_exit(t_all *a)
{
	mlx_delete_image(a->map->window, a->map->img[WALL]);
	mlx_delete_image(a->map->window, a->map->img[HERO]);
	mlx_delete_image(a->map->window, a->map->img[BACK]);
	mlx_delete_image(a->map->window, a->map->img[COLLECT]);
	mlx_delete_image(a->map->window, a->map->img[EXIT]);
	mlx_delete_texture(a->map->png[WALL]);
	mlx_delete_texture(a->map->png[HERO]);
	mlx_delete_texture(a->map->png[BACK]);
	mlx_delete_texture(a->map->png[COLLECT]);
	mlx_delete_texture(a->map->png[EXIT]);
	ft_deallocation_matrix(a->matrix->matrix);
	mlx_terminate(a->map->window);
	exit(1);
}
