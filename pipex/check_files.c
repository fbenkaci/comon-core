/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:13:47 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/09 11:54:17 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile_exist(char **av1)
{
	int	fd;

	if (access(av1[1], F_OK) == -1)
	{
		perror("Infile not exist");
		return (-1);
	}
	fd = open(av1[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	check_outfile_exist(char **av)
{
	int	fd;

	fd = 0;
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
