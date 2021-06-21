/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:02 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:21:07 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_itoa_u
** --------------------
** converts a string to base 16 (hexadecimal)
*/

static int	calculate_x(long long a)
{
	int			i;
	long long	ab;

	i = 0;
	ab = a;
	if (ab == 0)
		return (1);
	while (ab != 0)
	{
		ab = ab / 16;
		i++;
	}
	return (i);
}

static char	*ft_itoa_x(unsigned long a)
{
	int				i;
	int				length;
	unsigned long	rem;
	char			*string;

	length = calculate_x(a);
	if (a == 0)
	{
		string = ft_calloc(2, sizeof(char));
		string[0] = '0';
		return (string);
	}
	string = ft_calloc(length + 1, sizeof(char));
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
** convert_x
** --------------------
** converts an unsigned int value to base 16
** x displays the hexadecimal diggits a-f in lower case
** X displays them in uppercase
*/

int	convert_x(va_list ap, t_vault *data, int printed)
{
	unsigned int	num;
	char			*temp;
	char			*filler;
	char			*content;

	num = va_arg(ap, unsigned int);
	temp = ft_itoa_x(num);
	if (!temp)
		return (err_one_str(temp, data));
	content = add_content_u_x(temp, ft_strlen(temp), data, num);
	if (!content)
		return (err_two_str(temp, content, data));
	filler = add_filler_d_s_u_x(content, data);
	if (!filler)
		return (err_three_str(temp, content, filler));
	if (data->conv == 'X')
		upper_x(content);
	printed = print_str(data, content, filler, printed);
	free(temp);
	return (printed);
}
