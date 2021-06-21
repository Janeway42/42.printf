/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_d_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 19:30:37 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/01 21:12:22 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** content_d_zero
** --------------------
** copies the temp string to the content string
*/

char	*content_d_zero(int size, char *temp)
{
	int		i;
	char	*content;

	i = 0;
	content = ft_calloc(size + 1, sizeof(char));
	if (!content)
		return (NULL);
	if (size == 0)
		return (content);
	while (i < size)
	{
		content[i] = temp[i];
		i++;
	}
	return (content);
}

/*
** content_d_one
** --------------------
** fills with zero the precission and then 
** copies the temp string to the content string
*/

char	*content_d_one(int size, char *temp)
{
	int		j;
	char	*content;

	j = ft_strlen(temp);
	content = ft_calloc(size + 1, sizeof(char));
	if (!content)
		return (NULL);
	ft_memset(content, '0', size);
	while (j > -1)
	{
		content[size] = temp[j];
		j--;
		size--;
	}
	return (content);
}

/*
** content_d_three
** --------------------
** places the "-" of the negative number first
** fills with zero the precission and then 
** copies the temp string to the content string
*/

char	*content_d_two(int size, char *temp)
{
	int		j;
	char	*content;

	j = ft_strlen(temp);
	content = ft_calloc(size + 1, sizeof(char));
	if (!content)
		return (NULL);
	ft_memset(content, '0', size);
	content[0] = temp[0];
	while (j > 0)
	{
		content[size] = temp[j];
		j--;
		size--;
	}
	return (content);
}
