/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpopa <cpopa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 11:43:47 by cpopa         #+#    #+#                 */
/*   Updated: 2021/05/11 16:24:39 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_compare(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*copy_trim(char *result, const char *s1, int forward, int reverse)
{
	int	i;

	i = 0;
	while (forward + i <= reverse)
	{
		result[i] = s1[forward + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		forward;
	int		reverse;

	if (!s1 || !set)
		return (NULL);
	forward = 0;
	reverse = ft_strlen(s1) - 1;
	while (s1[forward] != '\0' && ft_compare(s1[forward], set) == 1)
		forward++;
	while (ft_compare(s1[reverse], set) == 1 && reverse >= 0)
		--reverse;
	if (reverse < 0 && forward > 0)
		result = (char *)malloc(sizeof(char) * 1);
	else
		result = (char *)malloc(sizeof(char) * (reverse - forward + 2));
	if (!result)
		return (NULL);
	return (copy_trim(result, s1, forward, reverse));
}
