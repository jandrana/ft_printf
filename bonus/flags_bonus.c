/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:18:10 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:45:19 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

void	ft_bpf_width(t_flag *fg, int *result, long long nbr)
{
	char	c;
	int		prec;

	prec = 0;
	if (fg->zero == 1)
		c = '0';
	else
		c = ' ';
	while (fg->width-- && (!fg->zero || nbr >= 0))
		ft_bpf_putchar(c, result);
}

void	ft_bpf_prec(t_flag *fg, int *result, long long nbr)
{
	(void)nbr;
	if (fg->prec < 0)
		return ;
	while (fg->prec--)
	{
		ft_bpf_putchar('0', result);
		fg->length += 1;
	}
	fg->prec = -1;
}

static void	handle_width_prec(t_flag *fg, char *str, va_list arg)
{
	int		stop;

	stop = 0;
	while (!stop && !ft_strchr("%cspdiuxX", *str))
	{
		if (*str == '.' && ++stop && ++str)
		{
			if (*str == '*')
				fg->prec = va_arg(arg, int);
			else
				fg->prec = ft_atoi(str);
		}
		else if (ft_strchr(" +#", *str))
			;
		else if (*str == '-')
			fg->left = 1;
		else if (*str == '0' && !fg->width)
			fg->zero = 1;
		else if (*str == '*' && !fg->width)
			fg->width = va_arg(arg, int);
		else if (!fg->width)
			fg->width = ft_atoi(str);
		++str;
	}
}

static void	sharp_space_sign(t_flag *fg, char c)
{
	if (c == '+')
		fg->sign = 1;
	else if (c == ' ')
		fg->space = 1;
	else if (c == '#')
		fg->sharp = 1;
}

int	assign_flags(t_flag *fg, char *str, va_list arg, int *result)
{
	fg->conv = 0;
	handle_width_prec(fg, str, arg);
	if (fg->width < 0)
	{
		fg->width *= -1;
		fg->left = 1;
	}
	while (str[fg->pos] && !ft_strchr("cspdiuUxX%", str[fg->pos]))
	{
		if (!ft_strchr("# +-.0%cspdiuxX*", str[fg->pos])
			&& !ft_isdigit(str[fg->pos]))
		{
			*result = -1;
			reset_flag(fg);
			return (1);
		}
		sharp_space_sign(fg, str[fg->pos]);
		fg->pos++;
	}
	fg->pos++;
	return (0);
}
