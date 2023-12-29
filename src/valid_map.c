/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:04:36 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 11:57:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_composition(char c)
{
	return (c == 'E' || c == 'P' || c == '1' ||
			c == 'C' || c == '0' || c == '\n');
}

void	ft_valid_this_fot_me(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (all->matrix->matrix[y])
	{
		x = 0;
		while (all->matrix->matrix[y][x])
		{
			if (all->matrix->matrix[y][x] == 'E')
				all->items->exit++;
			if (all->matrix->matrix[y][x] == 'P')
				all->items->player++;
			if (all->matrix->matrix[y][x] == '1')
				all->items->wall++;
			if (all->matrix->matrix[y][x] == 'C')
				all->items->collect++;
			if (all->matrix->matrix[y][x] == '0')
				all->items->empty++;
			if(!(ft_check_composition(all->matrix->matrix[y][x])))
				all->items->others++;
			x++;
		}
		y++;
	}
}

void	check_items_on_map(t_all *all)
{
	ft_valid_this_fot_me(all);
	if (all->items->exit > 1 || all->items->exit < 1)
		ft_error("ERROR 5! The map.bar has more exits than allowed!\n");
	if (all->items->player > 1 || all->items->player < 1)
		ft_error("ERROR 5! The map.bar has more heros than allowed!!\n");
	if (all->items->collect < 1)
		ft_error("ERROR 5! The map.bar has fewer collectables than mandatory!\n");
	if (all->items->others != 0)
	{
		ft_deallocation_matrix(all->matrix->matrix);
		ft_error("ERROR 5!  The map.ber has illegal characters\n");
	}
}

void	ft_valid_wall(t_all *a)
{
	int		y;
	int		x;

	y = 0;
	a->map->is_wrong = 0;
	while (a->matrix->matrix[y])
	{
		x = 0;
		while (x <= a->matrix->column -3)
		{
			if ((y == 0 && a->matrix->matrix[y][x] != '1') ||
				(y == a->matrix->line -2 && a->matrix->matrix[y][x] != '1'))
				a->map->is_wrong++;
			if ((x == 0 && a->matrix->matrix[y][x] != '1') ||
				(x == a->matrix->column -1 && a->matrix->matrix[y][x] != '1'))
				a->map->is_wrong++;
			x++;
		}
		y++;
	}
	if (a->map->is_wrong != 0)
	{
		ft_deallocation_matrix(a->matrix->matrix);
		ft_error("ERROR 6! The map.bar is not surrounded by walls\n");
	}
}

void	ft_valid_size(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (all->matrix->matrix[y])
	{
		x = 0;
		while (all->matrix->matrix[y][x] != '\0')
		{
			if (all->matrix->matrix[y][x] == '\n')
				break ;
			x++;
		}
		if(x != all->matrix->column)
		{
			ft_printf("ERROR 7! The map.bar has disproportionate columns = [%d] column [%d]",
				y, all->matrix->column);
						ft_deallocation_matrix(all->matrix->matrix);
						exit(1);
		}
		y++;
	}
}