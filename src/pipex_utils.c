/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:13:48 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 15:57:17 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

void	create_pipe(t_pipex *data)
{
	if (pipe(data->pipefd) == -1)
		handle_error(data, "Error creating pipe", EXIT_FAILURE);
}

pid_t	fork_process(void)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		perror("Error creating a new process");
	return (id);
}

void	execute_command(t_pipex *data)
{
	if (data->cmd_index == 0)
		redirect_io(data->input_fd, data->pipefd[1], data);
	else
		redirect_io(data->pipefd[0], data->output_fd, data);
	close_pipe_fds(data);
	if (execve(data->command_path, data->command_args, data->envp) == -1)
		handle_error(data, "Error executing child command", EXIT_FAILURE);
}

int	wait_for_children(t_pipex *data)
{
	int	i;
	int	status;

	i = 0;
	close_file_fds(data);
	close_pipe_fds(data);
	while (i < data->num_commands)
	{
		waitpid(data->pid[i], &status, 0);
		i++;
	}
	return (WEXITSTATUS(status));
}

void	redirect_io(int in, int out, t_pipex *data)
{
	if (dup2(in, STDIN_FILENO) == -1)
		handle_error(data, "dup2 failed", EXIT_FAILURE);
	if (dup2(out, STDOUT_FILENO) == -1)
		handle_error(data, "dup2 failed", EXIT_FAILURE);
}
