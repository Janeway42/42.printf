/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 14:11:53 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/01 10:30:40 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** set_precision
** --------------------
** sets data->prec - precision field
** returns location in string.
*/

static int	arg_precision(t_vault *data, va_list ap, int count)
{
	data->prec = va_arg(ap, int);
	if (data->prec < 0)
	{
		data->prec = 0;
		data->dzero = 0;
	}
	count++;
	return (count);
}

int	set_precision(const char *input, t_vault *data, va_list ap, int count)
{
	int		i;
	char	*str_precision;

	i = 0;
	if (*(input + count) == '.')
	{
		count++;
		data->dzero = 1;
	}
	if (*(input + count) == '*')
		return (arg_precision(data, ap, count));
	while (ft_isdigit(*(input + count + i)) == 1)
		i++;
	str_precision = ft_substr(input, count, i);
	if (!str_precision)
		return (-1);
	data->prec = ft_atoi(str_precision);
	free(str_precision);
	return (count + i);
}

/*
** set_width
** --------------------
** sets data->width - minimum width field
** returns location in string.
*/

int	set_width(const char *input, t_vault *data, va_list ap, int count)
{
	int		i;
	char	*str_width;

	i = 0;
	if (*(input + count) == '*')
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->dash = 1;
			data->width = data->width * -1;
		}
		count++;
		return (count);
	}
	while (ft_isdigit(*(input + count + i)) == 1)
		i++;
	str_width = ft_substr(input, count, i);
	if (!str_width)
		return (-1);
	data->width = ft_atoi(str_width);
	free(str_width);
	return (count + i);
}

/*
** set_flags
** --------------------
** set_flags sets data->dash to 1 if "-"" and "0" flags are present. 
** returns location in string.
*/

int	set_flags(const char *input, t_vault *data, int count)
{
	while (*(input + count) == '-' || *(input + count) == '0')
	{
		if (*(input + count) == '-')
			data->dash = 1;
		if (*(input + count) == '0')
			data->zero = 1;
		count++;
	}
	return (count);
}

/*
** set_conv
** --------------------
** stores the conversion data in the conversion_printf type structure
*/

int	set_conv(const char *fmt, t_vault *data, va_list ap, int count)
{
	int	steps;

	data->dash = 0;
	data->zero = 0;
	data->width = 0;
	data->prec = 0;
	data->dzero = 0;
	data->valid_conv = 0;
	data->backup = count;
	steps = set_flags(fmt, data, count);
	steps = set_width(fmt, data, ap, steps);
	steps = set_precision(fmt, data, ap, steps);
	steps = set_conversion(fmt, data, steps);
	return (steps);
}
