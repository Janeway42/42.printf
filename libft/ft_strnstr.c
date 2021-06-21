/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:50:15 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/11 16:24:25 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s == 0)
		return ((char *)b);
	if (ft_strlen(b) == 0)
		return (NULL);
	while (*b != '\0')
	{
		if (i + len_s > len)
			return (NULL);
		if (ft_strncmp(b, s, len_s) == 0)
			return ((char *)b);
		i++;
		b++;
	}
	return (NULL);
}
