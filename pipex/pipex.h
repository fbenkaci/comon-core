#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct pipex
{
	int		outputfd;
	int		inputfd;
	int		fd[2];
	int		id1;
	int		id2;
	char	**args;
	char	*path;
	char	**cmd;
}			pipex;

void		first_child(char **av, pipex *data, char **envp);
void		second_child(char **av, pipex *data, char **envp);
char		*command_loc(char **envp, char *av);
int			check_infile_exist(char **av1);
int			check_outfile_exist(char **av);
int			error_cmd(char **cmd);
void		executioon(pipex *data, char **envp);
void		ft_free_array(char **array);
void		duplication(pipex *data);
int			error_path(pipex *data);
int			init_first_child_process(char **av, pipex *data, char **envp);
int			init_second_child_process(char **av, pipex *data, char **envp,
				char **cmd);

#endif