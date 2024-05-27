/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:17:07 by ana-cast          #+#    #+#             */
/*   Updated: 2024/05/27 19:57:21 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[++count])
		;
	return (count);
}

static void	select_format(va_list arg, int value, int *result)
{
	if (value == 'c')
		ft_pf_putchar(va_arg(arg, int), result);
	else if (value == 's')
		ft_pf_putstr(va_arg(arg, char *), result);
	else if (value == 'p')
		ft_pf_pointer(va_arg(arg, unsigned long long), result);
	else if (value == 'd' || value == 'i')
		ft_pf_putnbr_base(va_arg(arg, int), DECIMAL, result);
	else if (value == 'u')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), DECIMAL, result);
	else if (value == 'x')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_LOW, result);
	else if (value == 'X')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_CAP, result);
	else if (value == '%')
		ft_pf_putchar('%', result);
	else
		*result = -1;
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_pf_putchar(str[i], &result);
		else if (str[i + 1])
			select_format(arg, str[++i], &result);
		i++;
	}
	va_end(arg);
	return (result);
}
