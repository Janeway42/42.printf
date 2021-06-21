/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:01:53 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:22:20 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*dest;
	unsigned char		for_c;

	i = 0;
	dest = str;
	for_c = c;
	while (i < n)
	{
		if (dest[i] == for_c)
			return ((void *)(dest + i));
		i++;
	}
	return (NULL);
}
