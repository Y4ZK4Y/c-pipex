/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:04:24 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 14:34:03 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		exit_status;

	validate_num_args(argc);
	data = initialize_pipex(argc, argv, envp);
	data.pid = allocate_memory(&data, (sizeof(int) * data.num_commands));
	create_pipe(&data);
	exit_status = pipex(&data);
	return (exit_status);
}
