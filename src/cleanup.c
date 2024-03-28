/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:23:34 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 12:47:41 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

void	free_pid(t_pipex *data)
{
	free(data->pid);
	data->pid = NULL;
}

void	cleanup(t_pipex *data)
{
	free_pid(data);
	close_file_fds(data);
	close_pipe_fds(data);
	free_2d((void ***)&data->command_args);
	free_nullify((void **)&data->command_path);
}

void	free_2d(void ***thing)
{
	int		i;
	void	**arr;

	i = 0;
	if (*thing == NULL)
		return ;
	arr = *thing;
	while (arr[i] != NULL)
	{
		free_nullify(&arr[i]);
		i++;
	}
	free(arr);
	*thing = NULL;
}

void	free_nullify(void **thing)
{
	free(*thing);
	*thing = NULL;
}
