/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:14:21 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/03 13:58:56 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	executioon(pipex *data, char **envp)
// {
// 	if (execve(data->path, data->args, envp) == -1)
// 	{
// 		perror("Execution: failed");
// 		exit(127);
// 	}
// }

int	error_cmd(char **cmd)
{
	if (!cmd)
	{
		perror("Memory allocation failed");
		return (1);
	}
	return (0);
}

// int	error_path(pipex *data)
// {
// 	if (!data->path)
// 	{
// 		perror("Command not found");
// 		free(data->path);
// 		exit(127);
// 	}
//     return (1);
// }