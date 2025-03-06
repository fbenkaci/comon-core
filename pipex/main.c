/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenkaci <fbenkaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:07:04 by fbenkaci          #+#    #+#             */
/*   Updated: 2025/03/04 15:22:08 by fbenkaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **av, pipex *data, char **envp)
{
	data->id1 = fork();
	if (data->id1 == 0)
	{
		close(data->fd[0]);
		data->cmd = ft_split(av[2], ' ');
		if (error_cmd(data->cmd) == 1)
		{
			close(data->fd[1]);
			exit(1);
		}
		data->path = command_loc(envp, data->cmd[0]);
		if (!data->path)
		{
			perror("Command not found");
			ft_free_array(data->cmd);
			free(data->path);
			close(data->fd[1]);
			exit(127);
		}
		data->args = ft_split(av[2], ' ');
		if (!data->args)
		{
			ft_free_array(data->cmd);
			close(data->fd[1]);
			exit(1);
		}
		data->inputfd = check_infile_exist(av);
		if (data->inputfd == -1)
		{
			ft_free_array(data->args);
			ft_free_array(data->cmd);
			free(data->path);
			close(data->fd[1]);
			exit(1);
		}
		if (init_first_child_process(av, data, envp) == 1)
			exit(1);
	}
}

int	init_first_child_process(char **av, pipex *data, char **envp)
{
	data->outputfd = check_outfile_exist(av);
	if (data->outputfd == -1)
	{
		ft_free_array(data->cmd);
		ft_free_array(data->args);
		free(data->path);
		close(data->fd[1]);
		return (1);
	}
	if (dup2(data->inputfd, 0) == -1 || dup2(data->fd[1], 1) == -1)
	{
		perror("dup2 of id1: failed");
		ft_free_array(data->cmd);
		ft_free_array(data->args);
		free(data->path);
		close(data->fd[1]);
		return (1);
	}
	ft_free_array(data->cmd);
	close(data->outputfd);
	close(data->inputfd);
	close(data->fd[1]);
	if (execve(data->path, data->args, envp) == 1)
	{
		perror("Execution: failed");
		ft_free_array(data->args);
		ft_free_array(data->cmd);
		return (1);
	}
	return (0);
}

void	second_child(char **av, pipex *data, char **envp)
{
	char	**cmd;

	data->id2 = fork();
	if (data->id2 == 0)
	{
		close(data->fd[1]);
		cmd = ft_split(av[3], ' ');
		if (error_cmd(cmd) == 1)
			exit(1);
		data->path = command_loc(envp, cmd[0]);
		if (!data->path)
		{
			ft_free_array(cmd);
			perror("Command not found");
			close(data->fd[0]);
			exit(127);
		}
		
		if (init_second_child_process(av, data, envp, cmd) == 1)
			exit(1);
	}
}

int args(pipex *data, char **av, char **cmd)
{
	data->args = ft_split(av[3], ' ');
	if (!data->args)
	{
		ft_free_array(cmd);
		free(data->path);
		close(data->fd[0]);
		exit(1);
	}
}

int	init_second_child_process(char **av, pipex *data, char **envp, char **cmd)
{
	data->outputfd = check_outfile_exist(av);
	if (data->outputfd == -1)
	{
		ft_free_array(cmd);
		free(data->path);
		return (1);
	}
	if (dup2(data->outputfd, 1) == -1 || dup2(data->fd[0], 0) == -1)
	{
		perror("dup2 of id2: failed");
		return (1);
	}
	ft_free_array(cmd);
	close(data->outputfd);
	close(data->fd[0]);
	if (execve(data->path, data->args, envp) == 1)
	{
		perror("Execution: failed");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	pipex	data;
	int		status;

	if (ac == 5)
	{
		if (pipe(data.fd) == -1)
		{
			perror("Pipe failed");
			return (1);
		}
		first_child(av, &data, envp);
		second_child(av, &data, envp);
		close(data.fd[1]);
		close(data.fd[0]);
		waitpid(data.id1, &status, 0);
		waitpid(data.id2, &status, 0);
		if (status == -1)
		{
			free(data.path);
			return (WEXITSTATUS(status));
		}
	}
	else
		write(1, "You must have 5 arguments.\n", 28);
	return (0);
}
