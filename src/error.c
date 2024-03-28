/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:27:09 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/25 12:47:35 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/libft/include/libft.h"

void	handle_error(t_pipex *data, const char *errormsg, int exit_code)
{
	perror(errormsg);
	cleanup(data);
	exit(exit_code);
}
