/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:56:11 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/02/27 17:33:38 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *img)
{
	if (!img || !img->mlx)
		return ;
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->Item)
		mlx_destroy_image(img->mlx, img->Item);
	if (img->perso)
		mlx_destroy_image(img->mlx, img->perso);
	if (img->background)
		mlx_destroy_image(img->mlx, img->background);
	if (img->Exit)
		mlx_destroy_image(img->mlx, img->Exit);
	return ;
}

void	coordonne_player(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->grid[i])
	{
		j = 0;
		while (img->grid[i][j] != '\0')
		{
			if (img->grid[i][j] == 'P')
			{
				img->player_x = j;
				img->player_y = i;
				break ;
			}
			j++;
		}
		if (img->grid[i][j] == 'P')
			break ;
		i++;
	}
}

int	close_window(t_data *img)
{
	free_images(img);
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
		mlx_destroy_display(img->mlx);
	free(img->mlx);
	free_map(img->grid);
	free_map(img->cpy_grid);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_data *img)
{
	if (keycode == XK_Escape)
		close_window(img);
	if (keycode == W)
	{
		ft_printf("%d\n", ++img->nb_moves);
		move_up(keycode, img);
	}
	if (keycode == S)
	{
		ft_printf("%d\n", ++img->nb_moves);
		move_down(keycode, img);
	}
	if (keycode == A)
	{
		ft_printf("%d\n", ++img->nb_moves);
		move_left(keycode, img);
	}
	if (keycode == D)
	{
		ft_printf("%d\n", ++img->nb_moves);
		move_right(keycode, img);
	}
	return (0);
}

void	run_game(t_data *img)
{
	coordonne_player(img);
	img->nb_moves = 0;
	mlx_hook(img->win, DestroyNotify, StructureNotifyMask, &close_window, img);
	mlx_hook(img->win, KeyPress, KeyPressMask, &keypress, img);
	mlx_loop(img->mlx);
}
