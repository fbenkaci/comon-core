/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:20:23 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/04 14:43:35 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img2(t_data *img)
{
	img->background = mlx_xpm_file_to_image(img->mlx, "background.xpm",
			&img->img_height, &img->img_width);
	if (!img->background)
	{
		mlx_destroy_image(img->mlx, img->wall);
		mlx_destroy_image(img->mlx, img->iitem);
		mlx_destroy_image(img->mlx, img->perso);
		return (0);
	}
	img->eexit = mlx_xpm_file_to_image(img->mlx, "exit.xpm", &img->img_height,
			&img->img_width);
	if (!img->eexit)
	{
		mlx_destroy_image(img->mlx, img->wall);
		mlx_destroy_image(img->mlx, img->iitem);
		mlx_destroy_image(img->mlx, img->perso);
		mlx_destroy_image(img->mlx, img->background);
		return (0);
	}
	return (1);
}

int	init_img(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "wall.xpm", &img->img_height,
			&img->img_width);
	if (!img->wall)
		return (0);
	img->iitem = mlx_xpm_file_to_image(img->mlx, "item.xpm", &img->img_height,
			&img->img_width);
	if (!img->iitem)
	{
		mlx_destroy_image(img->mlx, img->wall);
		return (0);
	}
	img->perso = mlx_xpm_file_to_image(img->mlx, "perso.xpm", &img->img_height,
			&img->img_width);
	if (!img->perso)
	{
		mlx_destroy_image(img->mlx, img->wall);
		mlx_destroy_image(img->mlx, img->iitem);
		return (0);
	}
	if (init_img2(img) == 0)
		return (0);
	return (1);
}

void	fill_map(t_data *img, int i, int j)
{
	while (img->grid[i] != NULL)
	{
		j = 0;
		while (img->grid[i][j])
		{
			if (img->grid[i][j] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall, i
					* WIDTH, j * HEIGHT);
			else if (img->grid[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->win, img->background, i
					* WIDTH, j * HEIGHT);
			else if (img->grid[i][j] == 'P')
				mlx_put_image_to_window(img->mlx, img->win, img->perso, i
					* WIDTH, j * HEIGHT);
			else if (img->grid[i][j] == 'E')
				mlx_put_image_to_window(img->mlx, img->win, img->eexit, i
					* WIDTH, j * HEIGHT);
			else if (img->grid[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->iitem, i
					* WIDTH, j * HEIGHT);
			j++;
		}
		i++;
	}
}

int	set_object(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!img->grid)
	{
		ft_printf("Error.\nmap ou img->grid est NULL.\n");
		return (1);
	}
	if (init_img(img) == 0)
	{
		ft_printf("Error.\nL'initialisation des images a échoué.\n");
		free_map(img->grid);
		free_map(img->cpy_grid);
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		return (1);
	}
	fill_map(img, i, j);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2)
	{
		if (verif_filename(av[1]) == 1)
			return (0);
		if (init_grid(&img, av) == 1)
			return (0);
		if (load_map(&img) == 1)
			return (0);
		img.mlx = mlx_init();
		if (!img.mlx)
		{
			free_map(img.grid);
			free_map(img.cpy_grid);
			ft_printf("Error.\nmlx_init() a échoué.\n");
			return (0);
		}
		img.win = mlx_new_window(img.mlx, 1920, 1080, "so_long!");
		if (set_object(&img) == 1)
			return (0);
		run_game(&img);
	}
	return (0);
}
