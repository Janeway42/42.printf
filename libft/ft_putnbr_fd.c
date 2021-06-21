/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 21:41:03 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/11 16:23:02 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	string;

	string = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		string = n * -1;
	}
	else
		string = n;
	if (string > 9)
		ft_putnbr_fd(string / 10, fd);
	ft_putchar_fd(string % 10 + 48, fd);
}
