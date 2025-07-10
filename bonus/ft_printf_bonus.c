/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:17:07 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:56:06 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

static void	check_flags(t_flag *fg)
{
	if (fg->space && (fg->sign || !ft_strchr("sdi", fg->conv)))
		fg->space = 0;
	if (fg->zero && (fg->left || fg->prec > -1
			|| !ft_strchr("diuxX", fg->conv)))
		fg->zero = 0;
	if (fg->sign && !ft_strchr("di", fg->conv))
		fg->sign = 0;
	if (fg->sharp && !ft_strchr("xX", fg->conv))
		fg->sharp = 0;
	if (fg->prec && !ft_strchr("sdiuxX", fg->conv))
		fg->prec = 0;
}

static void	select_format(va_list arg, t_flag *fg, int *result, char c)
{
	fg->conv = c;
	check_flags(fg);
	if (fg->conv == 'c' && ++fg->length)
		cs_conversions(fg, NULL, va_arg(arg, int), result);
	else if (fg->conv == 's')
		cs_conversions(fg, va_arg(arg, char *), 0, result);
	else if (fg->conv == 'p')
		p_conversion(fg, va_arg(arg, unsigned long long), result);
	else if (fg->conv == 'd' || fg->conv == 'i')
		diux_conversions(fg, va_arg(arg, int), \
		"0123456789", result);
	else if (fg->conv == 'u')
		diux_conversions(fg, va_arg(arg, unsigned int), \
		"0123456789", result);
	else if (fg->conv == 'x')
		diux_conversions(fg, va_arg(arg, unsigned int), \
		"0123456789abcdef", result);
	else if (fg->conv == 'X')
		diux_conversions(fg, va_arg(arg, unsigned int), \
		"0123456789ABCDEF", result);
	else if (fg->conv == '%')
		ft_bpf_putchar('%', result);
	else
		*result = -1;
	reset_flag(fg);
}

static t_flag	*init_flags(void)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->conv = 0;
	flag->sharp = 0;
	flag->space = 0;
	flag->sign = 0;
	flag->left = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->prec = -1;
	flag->pos = 0;
	flag->length = 0;
	return (flag);
}

static void	free_flags(t_flag **fg)
{
	if (fg)
		free(*fg);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		result;
	t_flag	*fg;

	i = -1;
	result = 0;
	va_start(arg, str);
	fg = init_flags();
	while (fg && str[++i] && result != -1)
	{
		if (str[i] != '%')
			ft_bpf_putchar(str[i], &result);
		else if (str[i + 1])
		{
			if (!assign_flags(fg, (char *)str + i + 1, arg, &result))
			{
				i += fg->pos;
				select_format(arg, fg, &result, str[i]);
			}
		}
	}
	free_flags(&fg);
	va_end(arg);
	return (result);
}
