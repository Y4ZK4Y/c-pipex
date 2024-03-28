/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   files.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:11:28 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 12:47:33 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

void	open_input_file(t_pipex *data)
{
	data->input_fd = open(data->input_file, O_RDONLY);
	if (data->input_fd == -1)
		handle_error(data, "Error opening the input file", EXIT_FAILURE);
}

void	open_output_file(t_pipex *data)
{
	data->output_fd = open(data->output_file, O_WRONLY | O_CREAT | \
														O_TRUNC, 0666);
	if (data->output_fd == -1)
		handle_error(data, "Error opening the output file", EXIT_FAILURE);
}
