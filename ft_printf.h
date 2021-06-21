/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 12:36:39 by janeway       #+#    #+#                 */
/*   Updated: 2021/05/13 13:10:54 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV "cspdiuxX%"

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

/*
** S_vault = structure used to store the conversion data needed to print
** ---------------------------------------------------------------------
** dash = the dash flag - left justify
** zero = numbers are padded with 0 up to the width field
** width = minimum field width
** prec = precision - varies based on conversion
** conv = conversion type flag 
** dzero = marker that indicates whether precision has been specified
** valid_conv = verifies that the conversion is valid
** backup = returns to the corect step point if there is no valid conversion
*/

typedef struct s_vault
{
	int		dash;
	int		zero;
	int		width;
	int		prec;
	char	conv;
	int		dzero;
	int		valid_conv;
	int		backup;
}				t_vault;

/*
** printf function
*/

int		ft_printf(const char *fmt, ...);
int		ft_script(const char *fmt, va_list ap, t_vault *data, int printed);

/*
** set s_vault data functions 
*/

int		set_conv(const char *fmt, t_vault *data, va_list ap, int count);
int		set_flags(const char *input, t_vault *data, int count);
int		set_width(const char *input, t_vault *data, va_list ap, int count);
int		set_precision(const char *input, t_vault *data, va_list ap, int count);
int		set_conversion(const char *input, t_vault *data, int count);

/*
** conversion functions
*/

int		convert(va_list ap, t_vault *data, int printed);
int		convert_c(va_list ap, t_vault *data, int printed);
int		convert_s(va_list ap, t_vault *data, int printed);
int		convert_d(va_list ap, t_vault *data, int printed);
int		convert_u(va_list ap, t_vault *data, int printed);
int		convert_x(va_list ap, t_vault *data, int printed);
int		convert_p(va_list ap, t_vault *data, int printed);

/*
** utility functions for conversions
*/

char	*upper_x(char *str);
char	*add_filler_c_per(t_vault *data);
char	*add_filler_d_s_u_x(char *str, t_vault *data);
char	*content_d_zero(int size, char *temp);
char	*content_d_one(int size, char *temp);
char	*content_d_two(int size, char *temp);
char	*content_p_one(char *str, int size);
char	*content_p_two(t_vault *data, char *str);
char	*add_content_u_x(char *str, int size, t_vault *data, int num);
char	*more_content_u_x(char *content, char *str, int size_c, int size);

/*
** utility functions for printing
*/

int		err_one_str(char *temp, t_vault *data);
int		err_two_str(char *temp, char *content, t_vault *data);
int		err_three_str(char *temp, char *content, char *filler);
int		print_str(t_vault *data, char *content, char *filler, int printed);

#endif
