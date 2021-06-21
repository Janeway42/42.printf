/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:02:28 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:22:09 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*for_dest;
	unsigned char	*for_src;
	unsigned char	for_c;
	size_t			i;

	for_dest = (unsigned char *)dest;
	for_src = (unsigned char *)src;
	for_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		for_dest[i] = for_src[i];
		if (for_src[i] == for_c)
			return (&for_dest[i + 1]);
		i++;
	}
	return (NULL);
}
