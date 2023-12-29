/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:17:52 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 15:03:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_valid_map	*ft_valid(void)
{
	static t_valid_map	mat;

	return (&mat);
}

void	ft_error(char *text)
{
	ft_printf(text, "\n");
	exit (1);
}

void	ft_mlx_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit (1);
}

char	*ft_validate_parameter(int argc, char *argv[])
{
	if (argc != 2)
		ft_error("ERROR!! You need to pass a .ber file as a parameter.");
	return (argv[1]);
}

void	ft_init(t_all *all)
{
	all->hero = ft_init_player();
	all->hero->movements = 0;
	all->items = ft_init_my_items();
	all->map = ft_init_mlx();
	all->matrix = ft_init_matrix();
	all->mat = ft_valid();
}

int	main(int argc, char *argv[])
{
	t_all		*all;

	all = ft_init_all();
	ft_init(all);
	all->archive_ber = ft_validate_parameter(argc, argv);
	matrix_load(all);
	ft_valid_wall(all);
	ft_valid_size(all);
	ft_flood_fill(all);
	check_items_on_map(all);
	ft_ask_hero_to_me(all);
	all->map->window = mlx_init(WIDTH, HEIGHT, "SO_LONG", true);
	ft_img_texture(all);
	ft_image_to_window(all);
	mlx_put_string(all->map->window, "0", 0, 0);
	mlx_key_hook(all->map->window, &ft_my_hooks, all);
	mlx_loop(all->map->window);
	ft_delete_img_texture_matrix_exit(all);
	return (0);
}
