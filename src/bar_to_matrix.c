/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:34:05 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 11:50:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_width_matrix(t_all *all)
{
	int		fd;
	char	*temp;

	fd = open(all->archive_ber, O_RDONLY);
	if (fd <= 0)
		ft_error("ERROR 1! Invalid file!\n");
	temp = get_next_line(fd);
	all->matrix->column = ft_strlen(temp) -1;
	all->mat->column = all->matrix->column;
	free(temp);
	close(fd);
}

void	line_matrix(t_all *all)
{
	int		fd;
	char	*temp;

	fd = open(all->archive_ber, O_RDONLY);
	if (fd <= 0)
		ft_error("ERROR 2! Invalid file!\n");
	all->matrix->x = 0;
	temp = "a";
	while (temp)
	{
		temp = get_next_line(fd);
		free(temp);
		all->matrix->y++;
		all->mat->line++;
	}
	close(fd);
	all->matrix->line = all->matrix->y;
}

void	matrix_load(t_all *all)
{
	char	*temp;
	int		fd;
	int		i;

	ft_width_matrix(all);
	line_matrix(all);
	if (all->matrix->line >= all->matrix->column)
		ft_error("ERROR 4! Wrong width and length!\n");
	all->matrix->matrix = ft_calloc(sizeof(char *), all->matrix->y);
	all->mat->mat = ft_calloc(sizeof(char *), all->matrix->y);
	if (!all->matrix->matrix)
		ft_error("ERROR 3! MEMORY ALLOCATION ERROR");
	fd = open(all->archive_ber, O_RDONLY);
	i = 0;
	temp = "a";
	ft_cpy_to_matrix(all, temp, fd, i);
	close(fd);
}

void	ft_deallocation_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_cpy_to_matrix(t_all *all, char *temp, int fd, int i)
{
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		all->matrix->x = ft_strlen(temp) + 1;
		all->mat->mat[i] = ft_substr(temp, 0, all->matrix->x);
		all->matrix->matrix[i] = ft_substr(temp, 0, all->matrix->x);
		if (!all->matrix->matrix[i])
		{
			ft_error("ERROR 5! MEMORY ALLOCATION ERROR");
			while (all->matrix->matrix[i--])
				free(all->matrix->matrix[i]);
			free(all->matrix->matrix);
		}
		free(temp);
		i++;
	}
}
