/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/06 16:14:22 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:18:01 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** add_content_d
** --------------------
** creates a string using the int value in decimal for and precision
*/

static char	*add_content_d(char *temp, int size, t_vault *data, int num)
{
	char	*content;

	if (num < 0)
	{
		if (data->prec > size - 1)
			content = content_d_two(data->prec + 1, temp);
		else if (data->zero == 1 && data->dzero == 0
			&& data->width > size && data->dash == 0)
			content = content_d_two(data->width, temp);
		else
			content = content_d_zero(size, temp);
	}
	if (num >= 0)
	{
		if (num == 0 && data->prec == 0 && data->dzero == 1)
			content = content_d_zero(0, temp);
		else if (data->prec > size && data->prec != 0)
			content = content_d_one(data->prec, temp);
		else
			content = content_d_zero(size, temp);
	}
	return (content);
}

/*
** convert_d
** --------------------
** converts an int value to a decimal form
*/

int	convert_d(va_list ap, t_vault *data, int printed)
{
	int		num;
	char	*temp;
	char	*filler;
	char	*content;

	num = va_arg(ap, int);
	temp = ft_itoa(num);
	if (!temp)
		return (err_one_str(temp, data));
	content = add_content_d(temp, ft_strlen(temp), data, num);
	if (!content)
		return (err_two_str(temp, content, data));
	filler = add_filler_d_s_u_x(content, data);
	if (!filler)
		return (err_three_str(temp, content, filler));
	printed = print_str(data, content, filler, printed);
	free(temp);
	return (printed);
}
