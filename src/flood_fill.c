/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:56:03 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 16:29:44 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_ask_back(t_all *a)
{
	int	y;
	int	x;

	y = 0;
	while (a->mat->mat[y])
	{
		x = 0;
		while (a->mat->mat[y][x] != '\0')
		{
			if (a->mat->mat[y][x] == '0')
			{
				a->mat->x = x;
				a->mat->y = y;
				break ;
			}
			x++;
		}
		if (a->mat->mat[y][x] == '0')
			break ;
		y++;
	}
}

void	flood_fill_helper(t_all *a, int x, int y)
{
	if (x < 0 || x >= a->mat->column || y < 0 || y >= a->mat->line || a->mat->mat[y][x] == '1' || a->mat->mat[y][x] == 'P')
	 	return ;
	a->mat->mat[y][x] = 'P';
	flood_fill_helper(a, x +1, y);
	flood_fill_helper(a, x -1, y);
	flood_fill_helper(a, x, y +1);
	flood_fill_helper(a, x, y -1);
}

void	ft_flood_fill(t_all *a)
{
	a->mat->x = 0;
	a->mat->y = 0;
	ft_ask_back(a);
	flood_fill_helper(a, a->mat->x, a->mat->y);
	ft_valid_compo(a);
	ft_deallocation_matrix(a->mat->mat);
}

void	ft_valid_compo(t_all *a)
{
	int	y;
	int	x;

	y = 0;
	while (a->mat->mat[y])
	{
		x = 0;
		while (a->mat->mat[y][x] != '\0')
		{
			if(a->mat->mat[y][x] != '1' && a->mat->mat[y][x] != 'P' && a->mat->mat[y][x] != '\n')
			{
				ft_deallocation_matrix(a->mat->mat);
				ft_deallocation_matrix(a->matrix->matrix);
				ft_error("ERROR 8! The map with no exit\n");
			}
			x++;
		}
		y++;
	}
}

void	ft_printmatrix(char **mat)
{
	int y;
	int x;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while(mat[y][x] != '\0')
		{
			ft_printf("%c", mat[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("\n");
}