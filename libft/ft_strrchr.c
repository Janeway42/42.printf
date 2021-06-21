/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 12:18:13 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:24:31 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*dest;

	dest = str;
	while (*dest)
		dest++;
	if (c == '\0')
		return ((char *)dest);
	while (dest >= str)
	{
		if (c == *dest)
			return ((char *)dest);
		dest--;
	}
	return (NULL);
}
