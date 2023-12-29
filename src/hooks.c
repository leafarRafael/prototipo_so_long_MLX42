/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:31:40 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 15:25:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_my_hooks(mlx_key_data_t keyd, void *param)
{
	t_all	*a;

	a = (t_all *) param;
	if (keyd.key == MLX_KEY_ESCAPE && keyd.action == MLX_PRESS)
		ft_delete_img_texture_matrix_exit(a);
	if (keyd.key == MLX_KEY_W && keyd.action == MLX_PRESS)
		ft_move_hero(a, -1, 0, PNG_HERO_UP);
	if (keyd.key == MLX_KEY_A && keyd.action == MLX_PRESS)
		ft_move_hero(a, 0, -1, PNG_HERO_LEFT);
	if (keyd.key == MLX_KEY_D && keyd.action == MLX_PRESS)
		ft_move_hero(a, 0, +1, PNG_HERO_RIGTH);
	if (keyd.key == MLX_KEY_S && keyd.action == MLX_PRESS)
		ft_move_hero(a, +1, 0, PNG_HERO_DOWN);
}
