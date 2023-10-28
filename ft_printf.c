/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:17:07 by ana-cast          #+#    #+#             */
/*   Updated: 2023/09/23 17:57:52 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
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
		ft_pf_putnbr_base(va_arg(arg, int), "0123456789", result);
	else if (value == 'u')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), "0123456789", result);
	else if (value == 'x')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef",
			result);
	else if (value == 'X')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF",
			result);
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
	while (str[i] && str && result != -1)
	{
		if (str[i] != '%')
			ft_pf_putchar(str[i], &result);
		else if (str[i + 1])
		{
			i++;
			if (str[i] == '%')
				ft_pf_putchar('%', &result);
			else
				select_format(arg, str[i], &result);
		}
		i++;
	}
	va_end(arg);
	return (result);
}
