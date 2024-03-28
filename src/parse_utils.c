/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/22 17:19:08 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/03/28 14:49:37 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#include "../lib/libft/include/libft.h"

char	*extract_env_variable(char **envp, const char *env_var_name)
{
	size_t	len;
	char	**env;

	len = ft_strlen(env_var_name);
	env = envp;
	while (*env != 0)
	{
		if (ft_strncmp(*env, env_var_name, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
		env++;
	}
	return (NULL);
}

char	**path_variable(char **envp)
{
	char	**directories;
	char	*path;

	path = extract_env_variable(envp, "PATH");
	if (path == NULL)
	{
		perror("Error extracting the PATH variable");
		return (NULL);
	}
	directories = ft_split(path, ':');
	if (directories == NULL)
	{
		perror("Error getting the PATH directories from ft_split");
		return (NULL);
	}
	return (directories);
}

bool	is_command_legit(char *command)
{
	if (access(command, F_OK | X_OK) == 0)
		return (true);
	return (false);
}

char	*constrcut_command(char *commandname, t_pipex *data)
{
	size_t	len;
	char	**path_v;
	char	*command_path;
	int		i;

	i = 0;
	path_v = path_variable(data->envp);
	if (path_v == NULL)
		handle_error(data, "PATH broken", EXIT_FAILURE);
	while (path_v[i] != NULL)
	{
		len = ft_strlen(path_v[i]) + ft_strlen(commandname) + 2;
		command_path = allocate_memory(data, len);
		ft_strlcpy(command_path, path_v[i], len);
		ft_strlcat(command_path, "/", len);
		ft_strlcat(command_path, commandname, len);
		if (is_command_legit(command_path))
			break ;
		free_nullify((void **)&command_path);
		i++;
	}
	free_2d((void ***)&path_v);
	return (command_path);
}

char	*find_command_path(char *commandname, t_pipex *data)
{
	char	*command_path;

	if (commandname == NULL || commandname[0] == '\0')
		handle_error(data, "Command is empty", EXIT_FAILURE);
	if (commandname[0] == '/' && is_command_legit(commandname) == true)
		return (ft_strdup(commandname));
	if (ft_strncmp(commandname, "./", 2) == 0)
		return (ft_strdup(commandname));
	command_path = constrcut_command(commandname, data);
	return (command_path);
}
