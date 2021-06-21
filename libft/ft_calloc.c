/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:21:21 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:20:54 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	result = malloc(nitems * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nitems * size);
	return (result);
}
