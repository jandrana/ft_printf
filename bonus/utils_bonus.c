/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:17:07 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:45:55 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			negative;
	int			result;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (((char *)str)[i] - '0');
		i++;
	}
	if (negative)
		result = -result;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

void	reset_flag(t_flag *fg)
{
	fg->space = 0;
	fg->sign = 0;
	fg->sharp = 0;
	fg->pos = 0;
	fg->width = 0;
	fg->zero = 0;
	fg->prec = -1;
	fg->left = 0;
	fg->length = 0;
}
