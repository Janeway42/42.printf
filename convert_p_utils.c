/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_p_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 20:14:57 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/01 20:09:45 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** content_p_one
** --------------------
** creates a content string 
*/

char	*content_p_one(char *str, int size)
{
	int		i;
	char	*content;

	i = ft_strlen(str);
	content = ft_calloc(size + 3, sizeof(char));
	if (!content)
		return (NULL);
	content[0] = '0';
	content[1] = 'x';
	while (i > -1)
	{
		content[i + 2] = str[i];
		i--;
	}
	return (content);
}

/*
** content_p_two
** --------------------
** creates a content string using the zero flag
*/

char	*content_p_two(t_vault *data, char *str)
{	
	int		i;
	int		j;
	char	*content;

	i = data->prec + 2;
	j = ft_strlen(str);
	content = ft_calloc(data->prec + 3, sizeof(char));
	if (!content)
		return (NULL);
	ft_memset(content, '0', data->prec + 2);
	content[0] = '0';
	content[1] = 'x';
	while (j > -1)
	{
		content[i] = str[j];
		j--;
		i--;
	}
	return (content);
}
