/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 18:50:28 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/01 21:05:59 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** set_conversion
** --------------------
** sets data->conv - conversion type specifier
** returns location in string.
** valid_conv checks if a valid conversion has been set
*/

static int	valid_conv(t_vault *data)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(CONV);
	while (i < size)
	{
		if (data->conv == CONV[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	set_conversion(const char *input, t_vault *data, int count)
{
	data->conv = *(input + count);
	if (valid_conv(data) == 1)
		data->valid_conv = 1;
	count++;
	return (count);
}
