/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 19:35:36 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/01 20:52:04 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** upper_x
** --------------------
** converts the string to capital letters
*/

char	*upper_x(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

/*
** add_filler_d_u_x
** --------------------
** creates the filler string for d, u and x/X conversions
*/

char	*add_filler_d_s_u_x(char *str, t_vault *data)
{
	int		size;
	int		size_content;
	char	c;
	char	*filler;

	c = ' ';
	if (data->zero == 1 && data->dzero == 0 && data->dash == 0)
		c = '0';
	size_content = ft_strlen(str);
	size = 0;
	if (data->width > size_content)
		size = data->width - size_content;
	filler = ft_calloc(size + 1, sizeof(char));
	if (!filler)
		return (NULL);
	filler = ft_memset(filler, c, size);
	return (filler);
}
