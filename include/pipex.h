/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:35:57 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/27 14:18:47 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdbool.h>

typedef struct s_pipex
{
	char		**input;
	char		*input_file;
	char		*output_file;
	int			input_fd;
	int			output_fd;
	int			num_commands;
	char		*command_path;
	char		**command_args;
	int			cmd_index;
	int			pipefd[2];
	int			*pid;
	char		**envp;
}				t_pipex;

/* initializer.c */
t_pipex	clean_slate(t_pipex *data);
t_pipex	initialize_pipex(int argc, char **argv, char **envp);

/* files.c */
void	open_input_file(t_pipex *data);
void	open_output_file(t_pipex *data);

/* pipex.c */
int		pipex(t_pipex *data);

/* ft_split */
//char	**ft_split(char const *s, char c);

/* parse_utils.c */
char	*extract_env_variable(char **envp, const char *env_var_name);
char	**path_variable(char **envp);
bool	is_command_legit(char *command);
char	*find_command_path(char *commandname, t_pipex *data);
char	*constrcut_command(char *commandname, t_pipex *data);

/* pipex_utils.c */
void	create_pipe(t_pipex *data);
pid_t	fork_process(void);
void	execute_command(t_pipex *data);
int		wait_for_children(t_pipex *data);
void	redirect_io(int in, int out, t_pipex *data);

/* cleanup.c */
void	free_pid(t_pipex *data);
void	cleanup(t_pipex *data);

void	free_nullify(void **thing);
void	free_2d(void ***thing);

/* utils.c */
void	*allocate_memory(t_pipex *data, size_t size);
void	validate_num_args(int argc);
void	close_file_fds(t_pipex *data);
void	close_pipe_fds(t_pipex *data);

/* error.c */
void	handle_error(t_pipex *data, const char *errormsg, int exit_code);

#endif
