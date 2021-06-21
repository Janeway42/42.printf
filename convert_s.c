/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 20:09:50 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:19:11 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** add_content_s
** --------------------
** creates a string using the fmt argument and precision
*/

static char	*add_content_s(char *string, t_vault *data)
{
	int		size;
	char	*content;

	size = ft_strlen(string);
	if (data->prec < size && data->prec != 0)
		size = data->prec;
	if (data->prec == 0 && data->dzero == 1)
		size = 0;
	content = ft_calloc(size + 1, sizeof(char));
	if (!content)
		return (NULL);
	content = ft_memcpy(content, string, size);
	return (content);
}

/*
** convert_s
** --------------------
** writes the characters pointed to by the argument
** stops writing when the number of bytes specified by the precision (if present)
** is reached or a null character is encountered
*/

int	convert_s(va_list ap, t_vault *data, int printed)
{
	char	*string;
	char	*filler;
	char	*content;

	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	content = add_content_s(string, data);
	if (!content)
		return (err_one_str(content, data));
	filler = add_filler_d_s_u_x(content, data);
	if (!filler)
		return (err_two_str(content, filler, data));
	printed = print_str(data, content, filler, printed);
	return (printed);
}
