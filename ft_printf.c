/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 12:43:13 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:44:26 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** convert
** --------------------
** identifies and accesses the appropriate conversion
*/

int	convert(va_list ap, t_vault *data, int printed)
{
	if (data->conv == 'c' || data->conv == '%')
		printed = convert_c(ap, data, printed);
	if (data->conv == 's')
		printed = convert_s(ap, data, printed);
	if (data->conv == 'd' || data->conv == 'i')
		printed = convert_d(ap, data, printed);
	if (data->conv == 'u')
		printed = convert_u(ap, data, printed);
	if (data->conv == 'x' || data->conv == 'X')
		printed = convert_x(ap, data, printed);
	if (data->conv == 'p')
		printed = convert_p(ap, data, printed);
	return (printed);
}

/*
** ft_script
** --------------------
** steps through the fmt argument and 
** prints regular characters or identifies conversions
*/

int	ft_script(const char *fmt, va_list ap, t_vault *data, int printed)
{
	int	steps;

	steps = 0;
	while (*(fmt + steps) != '\0')
	{
		if (*(fmt + steps) == '%')
		{
			steps = set_conv(fmt, data, ap, (steps + 1));
			if (steps == -1)
				return (-1);
			if (data->valid_conv == 0)
			{
				steps = data->backup;
				continue ;
			}
			printed = convert(ap, data, printed);
			if (printed == -1)
				return (-1);
			continue ;
		}
		write(1, fmt + steps, 1);
		steps++;
		printed++;
	}
	return (printed);
}

/*
** ft_printf
** --------------------
** printf returns the number of characters that are printed. 
**		If there is an error its return is negative.
** va_start(ap, fmt) - starts list (pointer to list + how many arguments)
** ft_script(fmt, ap, &data) - function to create the printed result. 
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_vault	data;
	int		result;

	result = 0;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	result = ft_script(fmt, ap, &data, result);
	va_end(ap);
	return (result);
}
