/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:18:16 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 12:46:56 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

void	*allocate_memory(t_pipex *data, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		handle_error(data, "Malloc failed", EXIT_FAILURE);
	return (ptr);
}

void	validate_num_args(int argc)
{
	if (argc != 5)
	{
		perror("more or less arguments than we need");
		exit(EXIT_FAILURE);
	}
}

void	close_file_fds(t_pipex *data)
{
	if (data->input_fd != -1)
	{
		close(data->input_fd);
		data->input_fd = -1;
	}
	if (data->output_fd != -1)
	{
		close(data->output_fd);
		data->output_fd = -1;
	}
}

void	close_pipe_fds(t_pipex *data)
{
	if (data->pipefd[0] != -1)
	{
		close(data->pipefd[0]);
		data->pipefd[0] = -1;
	}
	if (data->pipefd[1] != -1)
	{
		close(data->pipefd[1]);
		data->pipefd[1] = -1;
	}
}
