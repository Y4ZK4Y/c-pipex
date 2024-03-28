/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:06:08 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 15:55:48 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

int	pipex(t_pipex *data)
{
	int	exit_code;

	data->cmd_index = 0;
	while (data->cmd_index < data->num_commands)
	{
		data->command_args = ft_split(data->input[data->cmd_index + 2], ' ');
		if ((data->command_args) == NULL)
			handle_error(data, "ft_split failed", EXIT_FAILURE);
		data->command_path = find_command_path(data->command_args[0], data);
		if (data->command_path == NULL && data->cmd_index == 1)
			handle_error(data, "Command doesn't exist", EXIT_FAILURE);
		data->pid[data->cmd_index] = fork_process();
		if (data->pid[data->cmd_index] == -1)
			handle_error(data, NULL, EXIT_FAILURE);
		if (data->pid[data->cmd_index] == 0)
			execute_command(data);
		free_2d((void ***)&data->command_args);
		free_nullify((void **)&data->command_path);
		data->cmd_index++;
	}
	exit_code = wait_for_children(data);
	free_pid(data);
	return (exit_code);
}
