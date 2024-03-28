/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 15:49:13 by ykarimi       #+#    #+#                 */
/*   Updated: 2024/01/05 18:32:42 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Implementation of atoi - Convert a string to an integer.
** Standard C Library (libc, -lc)
** #include <stdlib.h>
** The  atoi() function converts the initial portion of the string pointed to
** by nptr to int.
** The converted value or 0 on error.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	is_negative;

	n = 0;
	is_negative = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_negative = (*str == '-');
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		n = (n * 10) - (*str - '0');
		str++;
	}
	if (is_negative)
		return (n);
	return (-n);
}
