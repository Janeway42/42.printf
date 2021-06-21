/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 17:41:59 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:18:44 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_itoa_p
** --------------------
** converts a string to base 16 (hexadecimal)
*/

int	calculate_p(long long a)
{
	int					i;
	unsigned long long	ab;

	i = 0;
	ab = (unsigned long long) a;
	if (ab == 0)
		return (1);
	while (ab != 0)
	{
		ab = ab / 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_p(unsigned long long a)
{
	int				i;
	int				length;
	unsigned long	rem;
	char			*string;

	length = calculate_p(a);
	string = ft_calloc(length + 1, sizeof(char));
	if (!string)
		return (NULL);
	if (a == 0)
		string[0] = '0';
	i = length - 1;
	while (a > 0)
	{
		rem = a % 16;
		if (rem <= 9)
			string[i] = rem + '0';
		if (rem > 9)
			string[i] = (rem - 10) + 'a';
		a = a / 16;
		i--;
	}
	return (string);
}

/*
** add_filler_p
** --------------------
** creates a string using using the lenght of content and minimum field width
*/

static char	*add_filler_p(char *str, t_vault *data)
{
	int		size;
	int		size_str;
	char	*filler;

	size_str = ft_strlen(str);
	if (data->width > size_str)
		size = data->width - size_str;
	else
		size = 0;
	filler = ft_calloc(size + 1, sizeof(char));
	if (!filler)
		return (NULL);
	filler = ft_memset(filler, ' ', size);
	return (filler);
}

/*
** convert_p
** --------------------
** creates a string using the converted memory location in base 16 and precision
*/

static char	*add_content_p(char *str, t_vault *data)
{
	int		size_str;
	char	*content;

	size_str = ft_strlen(str);
	if (data->prec > size_str + 2 && data->dzero == 1)
		content = content_p_two(data, str);
	else
		content = content_p_one(str, size_str);
	return (content);
}

/*
** convert_p
** --------------------
** converts a void * value to printable form
*/

int	convert_p(va_list ap, t_vault *data, int printed)
{
	unsigned long	address;
	char			*temp;
	char			*filler;
	char			*content;

	address = va_arg(ap, unsigned long);
	temp = ft_itoa_p(address);
	if (!temp)
		return (err_one_str(temp, data));
	content = add_content_p(temp, data);
	if (!content)
		return (err_two_str(temp, content, data));
	filler = add_filler_p(content, data);
	if (!filler)
		return (err_three_str(temp, content, filler));
	printed = print_str(data, content, filler, printed);
	free(temp);
	return (printed);
}
