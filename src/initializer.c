/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initializer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:09:45 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 15:57:50 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

t_pipex	clean_slate(t_pipex *data)
{
	data->pid = NULL;
	data->envp = NULL;
	data->input = NULL;
	data->input_file = NULL;
	data->output_file = NULL;
	data->num_commands = 0;
	data->command_path = NULL;
	data->command_args = NULL;
	data->cmd_index = 0;
	data->input_fd = -1;
	data->output_fd = -1;
	data->pipefd[0] = -1;
	data->pipefd[1] = -1;
	return (*data);
}

t_pipex	initialize_pipex(int argc, char **argv, char **envp)
{
	t_pipex	data;

	data = clean_slate(&data);
	data.input = argv;
	data.input_file = argv[1];
	data.output_file = argv[argc - 1];
	data.num_commands = argc - 3;
	data.envp = envp;
	open_input_file(&data);
	open_output_file(&data);
	return (data);
}
