/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 17:55:54 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:22:39 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*for_src;
	unsigned char	*for_dest;
	size_t			i;

	for_src = (unsigned char *)src;
	for_dest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n > 0)
		{
			for_dest[n - 1] = for_src[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		(for_dest)[i] = (for_src)[i];
		i++;
	}
	return (for_dest);
}
