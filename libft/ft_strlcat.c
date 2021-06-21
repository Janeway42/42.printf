/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:26:21 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:23:54 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	max_strlen(const char *str, size_t max_length)
{
	size_t	i;

	i = 0;
	while (i < max_length && str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i_src;
	size_t	orig_len_dest;

	i_src = 0;
	orig_len_dest = max_strlen(dest, n);
	while (orig_len_dest + i_src + 1 < n && src[i_src] != '\0')
	{
		dest[orig_len_dest + i_src] = src[i_src];
		i_src++;
	}
	if (orig_len_dest + i_src < n)
		dest[orig_len_dest + i_src] = '\0';
	return (orig_len_dest + ft_strlen(src));
}
