/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:10:59 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/29 15:26:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/lib_get_print/includes/get_next_line.h"
# include "../lib/lib_get_print/includes/ft_printf.h"
# include "../lib/lib_get_print/includes/libft.h"

# ifndef UP
#  define UP 'W'
# endif
# ifndef DOWN
#  define DOWN 'S'
# endif
# ifndef LEFT
#  define LEFT 'A'
# endif
# ifndef RIGHT
#  define RIGHT 'D'
# endif
# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 512
# endif

typedef enum e_type
{
    WALL = 0,
    EXIT,
    HERO,
    EMPTY,
    BACK,
    COLLECT,
	TEMP
} 			t_types;

# ifndef PNG_WALL
#  define PNG_WALL "./temp/tijolo.png"
# endif
# ifndef PNG_HERO_UP
#  define PNG_HERO_UP "./temp/arplaine_up.png"
# endif
# ifndef PNG_HERO_DOWN
#  define PNG_HERO_DOWN "./temp/arplaine_down.png"
# endif
# ifndef PNG_HERO_LEFT
#  define PNG_HERO_LEFT "./temp/arplaine_left.png"
# endif
# ifndef PNG_HERO_RIGTH
#  define PNG_HERO_RIGTH "./temp/arplaine_right.png"
# endif
# ifndef  PNG_BACK
#  define PNG_BACK "./temp/nigth.png"
# endif
# ifndef PNG_COLLECT
#  define PNG_COLLECT "./temp/star.png"
# endif
# ifndef PNG_EXIT
#  define PNG_EXIT "./temp/exit.png"
# endif

typedef struct s_matrix
{
	char	**matrix;
	int		line;
	int		column;
	int		x;
	int		y;
}				t_matrix;

typedef struct s_valid_map
{
	char	**mat;
	int		x;
	int		y;
	int		line;
	int		column;
}			t_valid_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	movements;
}				t_player;

typedef struct s_items_map
{
	int	empty;
	int	player;
	int	exit;
	int	collect;
	int	wall;
	int	others;
}				t_items;

typedef struct s_map
{
	int		is_wrong;
	int				s_y;
	int				s_x;
	mlx_t			*window;
	mlx_image_t		*img[7];
	mlx_texture_t	*png[7];
}				t_map;

typedef struct s_all_struct
{
	char		*archive_ber;
	t_map		*map;
	t_items		*items;
	t_player	*hero;
	t_matrix	*matrix;
	t_valid_map	*mat;
}				t_all;

// ber_to_matrix.c
void	ft_width_matrix(t_all *all);
void	line_matrix(t_all *all);
void	matrix_load(t_all *all);
void	ft_deallocation_matrix(char **matrix);
void	ft_cpy_to_matrix(t_all *all, char *temp, int fd, int i);

// hero.c
void	ft_ask_hero_to_me(t_all *a);
void	ft_move_hero(t_all *a, int up_down, int lef_rig, char *PNG);
void	ft_refresh(t_all *a, int up_down, int lef_rig, char *PNG);
void	ft_new(t_all *a, int x, int y, char *PNG);

// hooks.c
void	ft_my_hooks(mlx_key_data_t keyd, void *param);

// init_struct.c
t_matrix	*ft_init_matrix(void);
t_map	*ft_init_mlx(void);
t_items	*ft_init_my_items(void);
t_player	*ft_init_player(void);
t_all	*ft_init_all(void);

// matrix_to_window.c
void	ft_image_to_window(t_all *a);

// mlx_img_texture.c
void	ft_img_texture(t_all *a);
void	ft_resize_image(t_all *a);
void	ft_delete_img_texture_matrix_exit(t_all *a);

//valid_map.c
int		ft_check_composition(char c);
void	ft_valid_this_fot_me(t_all *all);
void	check_items_on_map(t_all *all);
void	ft_valid_wall(t_all *a);
void	ft_valid_size(t_all *all);

// main.c
void	ft_error(char *text);
void	ft_mlx_error(void);
char	*ft_validate_parameter(int argc, char *argv[]);
void	ft_init(t_all *all);
t_valid_map	*ft_valid(void);

//flood fill
void	ft_flood_fill(t_all *a);
void	flood_fill_helper(t_all *a, int x, int y);
void	ft_valid_compo(t_all *a);
void	ft_printmatrix(char **mat);

#endif
