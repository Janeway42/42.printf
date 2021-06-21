/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 15:04:27 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:13:59 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** add_filler_c_per
** --------------------
** creates a string using using the lenght of content and minimum field width
*/

char	*add_filler_c_per(t_vault *data)
{
	int		size;
	char	c;
	char	*filler;

	c = ' ';
	size = data->width - 1;
	if (data->width < 2)
		size = 0;
	filler = ft_calloc(size + 1, sizeof(char));
	if (data->zero == 1 && data->dash == 0)
		c = '0';
	if (!filler)
		return (NULL);
	filler = ft_memset(filler, c, size);
	return (filler);
}

/*
** convert_c
** --------------------
** displays and int value as an unsigned character
*/

int	convert_c(va_list ap, t_vault *data, int printed)
{
	unsigned char	c;
	char			*filler;

	c = '%';
	if (data->conv == 'c')
		c = va_arg(ap, int);
	filler = add_filler_c_per(data);
	if (!filler)
		return (err_one_str(filler, data));
	if (data->dash == 1)
	{
		ft_putchar_fd(c, 1);
		ft_putstr_fd(filler, 1);
	}
	else
	{
		ft_putstr_fd(filler, 1);
		ft_putchar_fd(c, 1);
	}
	printed += 1 + ft_strlen(filler);
	free(filler);
	return (printed);
}
