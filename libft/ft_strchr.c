/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:36:22 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:23:33 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	return ((void *)ft_memchr(str, c, i + 1));
}
