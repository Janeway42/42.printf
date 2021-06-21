/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 15:07:19 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:20:36 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_itoa_u
** --------------------
** converts a string to base 16 (hexadecimal)
*/

static int	calculate_u(unsigned int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_u(unsigned int n)
{
	char	*string;
	int		i;

	i = calculate_u(n);
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	string[i] = '\0';
	if (n == 0)
		string[0] = 48;
	while (n > 0)
	{
		string[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (string);
}

/*
** add_content_u
** --------------------
** creates a string using the converted memory location in base 10 and precision
*/

char	*more_content_u_x(char *content, char *str, int size_c, int size)
{
	ft_memset(content, '0', size_c);
	while (size > -1)
	{
		content[size_c] = str[size];
		size--;
		size_c--;
	}
	return (content);
}

char	*add_content_u_x(char *str, int size, t_vault *data, int num)
{
	int		size_c;
	char	*content;

	if (data->dzero == 1 && data->prec != 0 && data->prec > size)
		size_c = data->prec;
	else if (data->dzero == 1 && data->prec == 0 && num == 0)
		size_c = 0;
	else
		size_c = size;
	content = ft_calloc(size_c + 1, sizeof(char));
	if (!content)
		return (NULL);
	if (data->dzero == 1 && data->prec != 0 && data->prec > size)
		content = more_content_u_x(content, str, size_c, size);
	else
		content = ft_memcpy(content, str, size_c);
	return (content);
}

/*
** convert_u
** --------------------
** converts an unsigned int value to base 10
*/

int	convert_u(va_list ap, t_vault *data, int printed)
{
	unsigned int	num;
	char			*temp;
	char			*filler;
	char			*content;

	num = va_arg(ap, unsigned int);
	temp = ft_itoa_u(num);
	if (!temp)
		return (err_one_str(temp, data));
	content = add_content_u_x(temp, ft_strlen(temp), data, num);
	if (!content)
		return (err_two_str(temp, content, data));
	filler = add_filler_d_s_u_x(content, data);
	if (!filler)
		return (err_three_str(temp, content, filler));
	printed = print_str(data, content, filler, printed);
	free(temp);
	return (printed);
}
