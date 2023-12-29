/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:37:14 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/27 11:16:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_matrix	*ft_init_matrix(void)
{
	static t_matrix	matrix;

	return (&matrix);
}

t_map	*ft_init_mlx(void)
{
	static t_map	map;

	return (&map);
}

t_items	*ft_init_my_items(void)
{
	static t_items	items;

	return (&items);
}

t_player	*ft_init_player(void)
{
	static t_player	hero;

	return (&hero);
}

t_all	*ft_init_all(void)
{
	static t_all	all;

	return (&all);
}
