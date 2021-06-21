/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/21 10:45:09 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/06 10:16:55 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** err_one_str
** --------------------
** deals with the error  in case the first created string (temp) 
** does not exist 
*/

int	err_one_str(char *temp, t_vault *data)
{
	free(temp);
	if (data->conv == 'c')
		write(1, "error filler", 12);
	if (data->conv == 's')
		write(1, "error content", 13);
	else
		write(1, "error temp", 10);
	return (-1);
}

/*
** err_two_str
** --------------------
** deals with the error  in case the first two created strings 
** (temp and content) do not exist
*/

int	err_two_str(char *temp, char *content, t_vault *data)
{
	free(temp);
	free(content);
	if (data->conv == 's')
		write(1, "error filler", 12);
	else
		write(1, "error content", 13);
	return (-1);
}

/*
** err_three_str
** --------------------
** deals with the error  in case none of the created strings 
** (temp, content and filler) exist
*/

int	err_three_str(char *temp, char *content, char *filler)
{
	free(temp);
	free(content);
	free(filler);
	write(1, "error filler", 12);
	return (-1);
}

/*
** print_str
** --------------------
** prints the content and filler string in the right order
** using the dash flag (left align)
*/

int	print_str(t_vault *data, char *content, char *filler, int printed)
{
	if (data->dash == 1)
	{
		ft_putstr_fd(content, 1);
		ft_putstr_fd(filler, 1);
	}
	else
	{
		ft_putstr_fd(filler, 1);
		ft_putstr_fd(content, 1);
	}
	printed += ft_strlen(filler) + ft_strlen(content);
	free(filler);
	free(content);
	return (printed);
}
